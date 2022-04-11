
## 进程 - 操作系统最重要的

##### 主函数的返回值只能是unsigned short(0 - 255)

#### 进程的诞生
进程不是凭空产生的，是由父进程copy来的。
在linux系统中，所有的进程都是由1号进程copy来的
并且所有的进程都是由系统调用`fork()`出来的

在各个PID中，较为特别的是0号PID、1号PID和2号PID
##### 0号PID
为交换进程，属于内核进程，系统态，负责分页操作
我们熟悉的`bootloader`就是在这之前启动的

##### 1号为init进程，主要负责启动和关闭系统
我们通常将init称为1号进程，其实在刚才`kernel_init`的时候1号线程已经创建成功，
也可以理解`kernel_init`是1号进程的内核态，而我们所熟知的init进程是用户态的。
至此1号进程就完美的创建成功了，而且也成功执行了init可执行文件。

*注意1号进程之所以为1号进程是因为它是内核起来之后创建的
第一个进程，而不是说给他预留的1号PID*

##### 2号进程，是由1号进程创建的。
而且2号进程是所有内核线程父进程。

**所以说0号进程是1号和2号进程的父进程；1号进程是所有用户态进程的父进程；2号进程是所有内核线程的父进程。**

#### 那么fork()底层是怎么实现进程的copy的呢？
因为新的进程可能不需要父进程全部的数据，还需要一些其他的数据
这就涉及到写时拷贝(copy-on-write)

为了节省资源，进程的数据在发生变化的时候就要进行才进行拷贝。
不发生变化就和父进程共用一份进程空间即可(代码，数据都一样)

如果`fork()`出来不进行任何变化，子进程就继续做父进程的工作

子进程要想变声就要调用`ecec()`，变成新的进程了

#### 一个fork的小例子
```c
    pid_t pid;
    char *a = "abcd";
    pid = fork();
    if (pid == 0) {
        printf("Chlid : %d -> %d\n", getpid(), getppid());
    } else {
        printf("Father : %d\n", getpid());
    }
    printf("%s\n", a);
```

这种情况因为子进程和父进程都没有退出，所以会输出两遍
`abcd`

如果给子进程后边加上`exit(0);`
那么子进程就不会输出，只有父进程输出
这时再用`getpid, getppid`分别获取子进程和父进程的id

如果我们调换两行呢，让逻辑变成先输出父进程，随后结束
父进程，再输出子进程的相关信息
```c
    pid_t pid;
    char *a = "abcd";
    pid = fork();
    if (pid != 0) {
        printf("Father : %d\n", getpid());
    } else {
        printf("Chlid : %d -> %d\n", getpid(), getppid());
    }
    printf("%s\n", a);
```
发现子进程部分输出的父进程pid = 1
```shell
Father : 3658
abcd
Chlid : 3659 -> 1
abcd
```
这里的子进程因为没有了父进程所以变成了孤儿进程
系统会将所有的孤儿进程给1号进程(systemd)收养

但是想避免这种情况的发生，就要用到`wait()`
`int status; wait(&status)`

```c
    pid_t pid;
    int status;
    pid = fork();
    if (pid == 0) {
        printf("Chlid : %d -> %d\n", getpid(), getppid());
        exit(1);
    } else {
        pid = wait(&status);
        printf("Father : %d = %d\n", getpid(), status);
    }
```

这样输出的`status = 256`，这是个很奇怪的值哦
要是`exit(2), status = 512`
怎么不输出exit value呢？

实际上status里存的除了exit value，还有程序退出的原因
(可否理解为errno?)

其中exit value存储在低8位，用宏`WEXITSTATUS(status)`
```c
        if (WIFEXITED(status)) printf("exit status = %d\n", WEXITSTATUS(status));
```
就可以取到exit value
```shell

WIFEXITED(wstatus)
       returns true if the child terminated normally, that is, by calling exit(3) or _exit(2), or by
       returning from main().
       如果子进程正常的终结了就return true，子进程正常终结有这么几种情况：
       1. exit(3) 
       2. _exit(2)
       3. main() return 0;

WEXITSTATUS(wstatus)
       returns the exit status of the child.  This consists of the least significant 8 bits of the
       status argument that the child specified in a call to exit(3) or _exit(2) or as the argument
       for a return statement in main().  This macro should be employed only if WIFEXITED returned
       true.
```
#### 进程变身 exec()

进程是程序在内存中的镜像，进程是执行的程序

```shell
The  exec()  family  of  functions replaces the current process image with a new process image.
This causes the program that is currently
being run by the calling process to be replaced with a new program, with newly initialized stack,
heap, and (initialized and uninitialized) data segments.
```
exec用一个新的进程映像来取代当前的进程映像
具体怎么取代呢，就是说新的进程映像会有一个新的堆栈空间，和一个(初始化或为初始化的)代码段
##### 使用exec带来的变化
之前进程所有的信号都被丢弃(比如键盘的输入)；丢弃所有的内存锁；重置大多数进程相关的统计信息(运行时间，所占的资源)
`atexit() & on_exit()` 可以订制自己的退出方式，因为默认的`exit()`是释放内存，指针这种，当程序申请了pid之后
就需要用`atexit()`来注册一个自己的退出方式，free掉申请的pid 

#### exit()
`exit`是可以在任意一个地方结束整个程序，使用`return ;`只是退出了当前的函数或者主函数

##### 使用exit之后的操作:

1. 执行`atexit(), on_exit()`注册的事件
2. 关闭文件流(所有打开的文件都关闭)
3. 删除所有的临时文件tmpfile
4. 调用真实的退出函数`_exit()`:
    - 所有的文件关闭(fd)
    - 如果父进程有一个特殊的`wait`调用或者是收到了
    `SIGCHLD`信号，它会收到子进程终止的通知
    - 所有子进程都被过继给1号进程
    - 关闭信号量



#### 僵尸进程和孤儿进程
##### 僵尸进程:
   - 子进程想退出，但是父进程不调用`wait, waitpid`获取其状态信息
   - 这就导致子进程的进程描述符依然保存在系统中，pid不会释放
   - 继续占用系统资源

##### 孤儿进程:

- 父进程先与子进程退出，子进程继续运行变成孤儿进程
- 孤儿进程被init收养，无害
- 可根据孤儿进程实现*守护进程*

#### 程序、进程和线程

##### 程序：程序只是一个普通文件，保存在存储介质中。
它的可否执行是根据文件权限决定的，而不是说二进制文件都可以执行
大规模的二进制程序通常被称为应用

##### 进程：程序在内存的镜像，就是正在运行的程序，是资源分配的最小单位

进程除了二进制镜像之外，还有:
    1. 虚拟内存实例
        2. 内核资源
        3. 安全的上下文
        4. 一个或者多个线程

##### 所谓线程就是一个特殊的进程，线程是进程内的活动单元，是CPU调度的最小单位

每个线程有自己的虚拟存储器(之所以叫虚拟的是因为可能是和其他线程共用的，表现出来像自己的)，包括:
    1. 栈
    2. 进程状态如寄存器
    3. 指令指针

单个线程的进程中，进程即线程

系统通过PID来判断进程是否还存在
```shell
❯ cat /proc/sys/kernel/pid_max
32768
```

### 高级进程管理

#### 进程状态:

- **阻塞**: 
    - 正在睡眠，等待IO或者信号来执行下一步
- **就绪** :
    - 进程获得所需的资源，可以进行下一步执行
- **运行** 

#### 进程调度
现在处理器基本都是抢占式
协同式是指每个进程占用固定的CPU时间

##### 协同式
##### 抢占式:

- 传统Unix会给所有就绪的进程分配时间片
- 当进程消耗完自己的时间片，就会被挂起，开始远行下一个进程
- 如果系统中没有就绪进程，则内核为已经执行完的进程重新分配时间片
- 所有进程最后都有机会运行，即使有更高优先级的进程

##### 完全公平调度器(CFS):

- CFS给N个进程分配1/N个处理器
- 通过nice value(优先级)权衡分配比例，重新分配(优先级是从-20～19)
- 默认的优先级是0，权值是1
- 优先级越小，权值随之越高
- 最小粒度
- 目标延时

#### CPU亲和力
调度器必须尽量充分利用处理器的性能，负载均衡
调度器应该还尽量把一个再次执行的进程放在原来处理器上运行(有点像`bind()`) -- 当然Linux系统也是这么做的

如果进程在处理器间迁移，会造成:
    1. 进程不能再使用缓存数据
    2. 原处理器中的缓存信息必须标记为无效(进程已经走了，用不到了)
    3. 进程在处理器迁移的最大损失就是缓存效应(时间局部性)

##### 软亲和力
Linux kernel 尽量将进程安排在它之前在的处理器上，除非处理器负载极端不平衡，才考虑在处理器间迁移。
##### 硬亲和力
进程和处理器绑定(进程极度依赖缓存)
```c
int sched_setaffinity(pid_t pid, size_t cpusetsize, const cpu_set_t *mask);
int sched_getaffinity(pid_t pid, size_t cpusetsize, cpu_set_t *mask);
```

所以说今天学的这些能干什么呢？-- 可以用来实现一个实时进程(比如我觉得能在DBMS系统中来发紧急警告信息，
单独给这个进程绑定一个CPU，一直空闲着，等待报警信息)
**父进程绑定在某处理器上，其fork出来的子进程也会继承相关特性**




#### 时间片

##### IO约束性进程和CPU约束型进程
- 多数时间处于阻塞状态等待资源的进程是IO约束型进程
- 一直消耗完所有时问片的进程为处理器约束型进程
- IO约束型需要更短的时问片
- CPU约束型需要更长的时间片
以top的结果为例
```shell
Processes: 491 total, 4 running, 487 sleeping, 2082 threads
```
可以看到，绝大部分的程序都是sleeping状态，也就是IO约束型进程
像我们之后写的socke编程，一开始是有一个死循环让程序不退出
那么这个程序即使没有任何连接他也是占满用了一个核心的资源


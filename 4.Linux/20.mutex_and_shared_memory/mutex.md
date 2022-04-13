
## 共享内存、互斥锁和信号机制

#### 用共享内存 + 信号(signal, kill)实现进程间通信

我们将init共享内存的代码封装一下:

 ```c
  char *get_shm(char *path, int id, int *shmid) {
         char *shared_memory = NULL;
         key_t key = ftok(path, id);
         if ((*shmid = shmget(key, sizeof(struct Msg), IPC_CREAT | 0666)) < 0) {
             perror("shmget");
         }
         if ((shared_memory = shmat(*shmid, NULL, 0)) == NULL) {
             perror("shmat");
         }
         return shared_memory;
     }
 ```



```c
#define ID 8888
char *shared_memory = NULL;
void *print(int i) {
    printf("{Father} : %s = %d\n", shared_memory, i);
    return NULL;
}
int main() {
    int shmid;
    pid_t pid;
    shared_memory = get_shm(".", ID, &shmid);
    // 前两个参数要传给ftok  
    // shmid要改变它的值的，后面要用它来判断创建shm是否成功
    // 所以说要传地址进去
    if ((pid = fork()) < 0) {
        perror("fork");
        exit(1);
    }
    if (pid == 0) {
        for (; ;) {
            printf("<child> : \n");
            scanf("%s", shared_memory);
            kill(getppid(), 32);
            // 在子进程中向共享内存读数据，并且传递32信号
            // 虽然signal是int型的，但是只有低8位有用，存的是信号值
        }
    } else {
        for (; ;) {
            signal(32, print(1));
            printf("<Father> :  %s\n", shared_memory);
            sleep(4);
            // 将print注册到32信号上，也就是一来32信号就调用print函数
            // 这里因为是unix系统，所以必须再传入一个int，print也得是void * 
        }
    }
    return 0;
}

```


#### 下面展示两个程序间的 shm + signal 通信，其实也是进程间的

这是1，2进程都要用到的结构体和初始化共享内存区
```c
struct Msg {
    pid_t pid;
    char message[1024];
};

void *shared_memory = NULL;
```
```c
child : 
int main() {
    int shmid;
    get_shm(".", ID, &shmid);
    //其实这几行克i一封装一下成get_shm()
    for (;;) {
        scanf("%s", msg->message);
        kill(msg->pid, 10);
    }
    return 0;
}
```
`kill`这里传递的是10信号
```c
void print() {
    printf("%s\n", msg->message);
}
int main() {
    int shmid;
    signal(10, print);
    //这里给print函数注册到10信号上
    //kill就能用共享内存给本程序传递10信号并且调用print函数
    shared_memory = get_shm(".", ID, &shmid);
    msg->pid = getpid();
    for (;;) {
        pause();
    }
    return 0;
}
```

`key_t ftok(const char *pathname, int proj_id);`
ftok 传入的参数有合法的路径和任务id，这个id可以是任意值
其返回值key是作为第一个参数传入shmget的
`ftok - convert a pathname and a project identifier to a System V IPC key`
它的作用就是制造出一个IPC的键

#### 下面给加锁

重新设计的Msg结构体
```c
struct Msg {
    char message[32];
    pthread_mutexattr_t m_attr;
    pthread_mutex_t mutex;
};
```
m_attr 是定义的mutex的属性
mutex 是锁
下面的`pthread_mutexattr_init`顾名思义，就是初始化锁的属性

```c
int main() {
    int shmid;
    msg = (struct Msg *)get_shm(".", 8731, &shmid);
    if (msg == NULL) {
        exit(1);
    }
    pthread_mutexattr_init(&msg->m_attr);
    pthread_mutexattr_setpshared(&msg->m_attr, PTHREAD_PROCESS_SHARED);
    pthread_mutexattr_setrobust(&msg->m_attr, PTHREAD_MUTEX_ROBUST);
    pthread_mutex_init(&msg->mutex, &msg->m_attr);
    for (;;) {
        pthread_mutex_lock(&msg->mutex);
        printf("<Output> : %s\n", msg->message);
        // 在访问message之前加锁，这样同时只能有一个进程访问
        // 这样两个进程就会竞争这个资源，看谁能抢到这个锁
        pthread_mutex_unlock(&msg->mutex);
        usleep(300);
    }

    return 0;
}
```


```c
int main() {
    int shmid;
    msg = (struct Msg *)get_shm(".", 8731, &shmid);
    if (msg == NULL) {
        exit(1);
    }
    pthread_mutexattr_init(&msg->m_attr);
    pthread_mutexattr_setpshared(&msg->m_attr, PTHREAD_PROCESS_SHARED);
    pthread_mutex_init(&msg->mutex, &msg->m_attr);
    for (;;) {
        pthread_mutex_lock(&msg->mutex);
        printf("<Input> : ");
        scanf("%s", msg->message);
        pthread_mutex_unlock(&msg->mutex);
    }
    return 0;
}
```

#### mutex中的条件变量
`pthread_cond_t c; `
`pthread_condattr_t c_attr; `
`pthread_condattr_init(&c_attr); `
`pthread_cond_init(&cond, &c_attr);`
`pthread_cond_signal(pthread_cond_t *cond) pthread_cond_signal – unblock a thread waiting for a condition variable`
`int pthread_cond_wait(pthread_cond_t *cond, pthread_mutex_t *mutex);`

`signal & wait`一般配对使用，wait 会执行两个原子操作:
    1. 给mutex解锁
    2. 把调用线程睡眠，直到cond被singal调用，wait返回前还会重新对mutex上锁

也就是将mutex的锁解开由cond阻塞

**没办法让进程结束的时候自动释放锁和条件变量，所以需要手动释放**





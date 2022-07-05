
## C++线程池的设计于实现

以往我们程序都是基于单线程顺序执行的
但是在Linux我们学习了多线程之后编程的方式就发生了变化
但是多线程编程确实是比较的不方便
首先要连接`-pthread`库
并且要设计相关的程序入口
并且不是所有的算法都能用多线程来实现

线程池就能帮助我们管理多线程程序
在线程池中需要关注的量有:
    1. 线程的数量
    2. 能执行传入的任意函数
    3. 可以根据传入的函数设置的优先级去执行顺序


##### 怎样实现执行传入的任意函数？
可以利用封装的思想，函数是不统一的，他们的返回值和参数都不一样
但是可以把fun都封装成task类，每个task类对外的表现就一样了
将task放到队列中，线程池从队列中取task
待执行的程序将task放到队列中
这就形成了所谓的**生产者消费者模型**

#### 怎样实现优先级？
优先级在任务队列中的表现就是其在队列中的位置
就是下标呗！
优先级高的排前边

整个任务队列就是优先级的优先队列`priority_queue`

#### task类的设计与实现

线程池中有两大类：线程池类和任务类
其中任务类应该接收函数及其参数
返回的是一个封装好的Task类的对象

```c++
namespace haizei {
class Task {
public :
    template<typename Func_T, typename ...ARGS>
    Task(Func_T f, ARGS ...args) {
        func = std::bind(f, args...);
    }
    void run() { func(); }

private :
    std::function<void()> func;
};
}
```
bind是将函数及其参数都绑定到一个新的函数上
但是代码这么写是有bug的
不能实现完美转发
写个例子测试下
```c++
void foo(int x, int y) {
    cout << x << y << endl;
}
int main() {
    int n = 123;
    haizei::Task t(foo, 1, n);
    t.run();
    return 0;
}
```
这样是可以正常运行的，但是如果我们将传递的值换成引用
并且在foo中对其进行操作
```c++
void foo(int x, int &y) {
    y += 2;
    cout << x << y << endl;
}
int main() {
    int n = 123;
    haizei::Task t(foo, 1, n);
    t.run();
    cout << n << endl;
    return 0;
}
```
输出结果是
1125
123
可见并没有对n的值进行修改，函数func是将`&n`的值又拷贝
了一份，没有实现完美转发
还记得我们之前学过的完美转发么
`forward`就是不许`bind`改动传入的函数及其参数类型
```c++
namespace haizei {
class Task {
public :
    template<typename Func_T, typename ...ARGS>
    Task(Func_T f, ARGS ...args) {
        func = std::bind(f, std::forward<ARGS>(args)...);
    }
    void run() { func(); }

private :
    std::function<void()> func;
};
}

void foo(int x, int &y) {
    y += 2;
    cout << x << y << endl;
}
int main() {
    int n = 123;
    haizei::Task t(foo, 1, std::ref(n));
    t.run();
    cout << n << endl;
    return 0;
}
```
注意传入n要传入n的引用
n是左值

# 函数

   一个普通函数范式张这样
   ```
       int is_prime(int x) {
           代码
       }
   ```
   返回值 函数名(参数声名列表) 声名和定义是两个完全不同的概念

## 递归程序

   他不是一种算法,只是一种编程技巧,他的作用和三个循环是一样的!
   ### 编写递归函数:

     1. 给予递归函数一个语义信息
     2. 边界条件处理
     3. 针对问题处理过程 和 递归过程 
     4. 结果返回(不仅仅是简单的return一下)

```
int f(int n) {
    if (n == 0) return 1; // 边界条件 写在前面才不会无限展开 展开道这里就停止了
    return n * f(n - 1); //递归公式
}

int main() {
    return 0;
}
```

   ### 函数指针

   函数当成参数传递给另一个函数,应用在分段函数上.
   一般形式的函数指针 `int ((*fun)(int))` 传入的是int 型 传出的也是int型



   ### 函数声名与定义

   我们在使用函数的时候只用知道他的声名而不用知道他的定义
   不妨通过一个实例
   ```
   
int funA(int a) {
    printf("funA = %d", a);
    if (a == 0) return 0;
    funB(a - 1);
    return a;
}

int funB(int b) {
    printf("funB = %d", b);
    if (b == 0) return 0;
    funA(b - 1);
    return b;
}

int main() {
    funA(6);
    funB(6);

    return 0;
}
   ```

运行,发现报错
```
function.c: In function ‘funA’:
function.c:13:5: warning: implicit declaration of function ‘funB’; did you mean ‘funA’? [-Wimplicit-function-declaration]
     funB(a - 1);
     ^~~~
     funA

```
未声名(undeclaration)的错误,那我们就在文件前边加上声名.

```
int funA(int )
int funB(int )
```

   这个未声名是语法错误,那我不禁猜想了.要是只有声名的话,肯定不会有语法错误
   令人印象深刻的是,报的错误是不同的
   ```
   /usr/bin/ld: /tmp/cc6yuPTz.o: in function `main':
function.c:(.text+0xa): undefined reference to `funA(int)'
/usr/bin/ld: function.c:(.text+0x14): undefined reference to `funB(int)'
collect2: error: ld returned 1 exit status

   ```


   这里说cc6yuPTz.o里的funA未定义,这就奇怪了哈.上一个报错是c代码里的
   这就不得不说到C语言可运行程序的四步
   预处理--> 编译--> 链接 -->可执行程序
              这一步会生成对象文件
              即.o(obj)
    一个源文件对应一个对象文件,并且源文件只要没有语法错误,就能够生成
    对象文件.不同的源文件之间存放的是不同函数的定义,所以函数的定义的错误
    *是在链接阶段报的错*.你想啊,编译阶段不会检查说你这个函数
    在别处定没定义,而是说只检查了你的函数名字变量对不对啊这种.








/*************************************************************************
	> File Name: 13.pointer.c
	> Author: 任博宇 
	> Mail: renboyu@hrbeu.edu.cn / renboyu2333@gmail.com
	> Created Time: Tue Oct 12 11:02:26 2021
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define pchar char *
typedef char * ppchar;

//#define offset(T, a) ({ \
//    T temp; \
//    (char *)(&temp.a) - (char *)(&temp); \
//})
//可是我们的宏定义一个temp临时变量，这样对于很大的结构体来说不好
#define offset(T, a) (long long)(&((T *)(NULL))->a)
struct Data {
    int a;
    double b;
    char c;
};

int main() {
    int num = 0x616263;
    // 将num四字节整形看成是四字节的数组，强转成char输出。
    //这一行我们会发现输出的是cba，这就和上节课讲的大小端系统有关了
    //num的0，1，2三位分别存放到了内存的低地址->高地址。输出的时候也是从高到低输出的。
    int num2 = 0x61626364;
    //输出num2 + 1，结果是cba。这里又是上上节的知识。num2指针是有类型的，指针+1向后跳该类型的大小。
    //即int4位，那么为什么跳到num的位置了呢。
    //在程序中我们数据是存在数据段，数据段是栈，地址由低向高增长。加上小端机的原因
    //最终num2和num的存储就是[64, 63, 62, 61, 63, 62, 61];
    printf("%s\n", (char *)(&num2 + 1));
    //下面实现一个输出结构体元素偏移量的功能
    printf("%lld\n", offset(struct Data, a)); 
    //这里的offset传入参数是(type, val) 我们除了获取变参列表中的va_arg函数之外，没见其他的
    //所以这里的offset显然是个宏。
    printf("%lld\n", offset(struct Data, b)); 
    printf("%lld\n", offset(struct Data, c)); 

    pchar p1, p2;
    ppchar p3, p4;
    printf("sizeof(p1) = %lu sizeof(p2) = %lu\n", sizeof(p1), sizeof(p2));
    printf("sizeof(p3) = %lu sizeof(p4) = %lu\n", sizeof(p3), sizeof(p4));
    //这里我们发现p2的大小为1字节
    //44行展开后为char * p1, p2;
    //也就是define真的是简单的替换 typedef才是新的类型
    return 0;
}

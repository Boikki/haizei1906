/*************************************************************************
	> File Name: 12.union.c
	> Author: 任博宇 
	> Mail: renboyu@hrbeu.edu.cn / renboyu2333@gmail.com
	> Created Time: Mon Sep 27 09:54:39 2021
 ************************************************************************/

//本程序实现的功能:将ip地址转换成对应的整形
//正好用到了联合体的共用一块存储区的特性
#include <stdio.h>

union IP {
    int num;
    struct {
        unsigned char a1;
        unsigned char a2;
        unsigned char a3;
        unsigned char a4;
    } ip;
};
//num和struct ip共用一块32位的存储空间
int is_little() {
    static int x = 1;
    return ((char *)&x)[0];
}
//此函数完成了检测大小端系统
//将int x 视为一个4位char字符串，取x的第一个字节
//这里用union也可

int main() {

    char str[100];
    int a[4];
    union IP p;
    is_little() && printf("LITTLE\n");
    while (~scanf("%s", str)) {
        sscanf(str, "%d.%d.%d.%d", a, a + 1, a + 2, a + 3);
        p.ip.a1 = a[0];
        p.ip.a2 = a[1];
        p.ip.a3 = a[2];
        p.ip.a4 = a[3];
        printf("%d\n", p.num);
    }

    
    //但是在程序运行完我们发现192.168.0.1和192.168.0.2间
    //本应差1，实际上却差了很多
    //这是因为我们的机器是小端机
    //小端机就是将数据的低位存在低地址位
    //打个比方，个位存在了0号地址，千位存在3号地址
    //这就是小端机。输出的时候是从低地址向高地址输出
    //读数据的时候一样是从高地址向低地址读
    //也就是小端机和地址增长的方向相反，大端机相同
    return 0;
}

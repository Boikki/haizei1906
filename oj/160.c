/*************************************************************************
	> File Name: 160.c
	> Author: 任博宇 
	> Mail: renboyu@hrbeu.edu.cn / renboyu2333@gmail.com
	> Created Time: Wed Sep 15 10:27:56 2021
 ************************************************************************/

#include <stdio.h>
#include <math.h>
#define PI 3.14

int main() {
    double r, h;
    scanf("%lf%lf", &r, &h);
    printf("%.2lf", ((PI * r * r + r * r * 4) + (PI * r + 2 * r + 2 * pow(2, 0.5) * r) * h));


    return 0;
}

/*************************************************************************
	> File Name: 163.c
	> Author: 任博宇 
	> Mail: renboyu@hrbeu.edu.cn / renboyu2333@gmail.com
	> Created Time: Fri Sep 17 09:40:39 2021
 ************************************************************************/

#include <stdio.h>
#include <math.h>
#define PI acos(-1)

int main() {
    double a, b, c;
    scanf("%lf %lf %lf", &a, &b, &c);
    double angel = c / 180 * PI;
    printf("%.6lf", pow((a * a + b * b - (a * b * cos(angel) * 2)), 0.5)); 
    return 0;
}

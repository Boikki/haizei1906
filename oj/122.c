/*************************************************************************
	> File Name: 122.c
	> Author: Boyu Ren
	> Mail: renboyu2333@gmail.com
	> Created Time: Mon 30 Aug 2021 03:22:19 PM CST
 ************************************************************************/

#include<stdio.h>

int main() {
    int t;
    scanf("%d", &t);

    if (t < 43200) {
        printf("%02d:%02d:%02d am", t / 3600, t % 3600 / 60, t % 60);

    } else if (t < 46800) {
        printf("%02d:%02d:%02d midnoon", t / 3600, t % 3600 / 60, t % 60);
        
    } else {
        
        printf("%02d:%02d:%02d pm", t / 3600 - 12, t % 3600 / 60, t % 60);
    }
    return 0;
}

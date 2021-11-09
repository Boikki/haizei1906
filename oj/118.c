/*************************************************************************
	> File Name: 118.c
	> Author: Boyu Ren
	> Mail: renboyu2333@gmail.com
	> Created Time: Sun 29 Aug 2021 04:37:24 PM CST
 ************************************************************************/

#include<stdio.h>

char animal[][10] = {
                   "rat", "ox", "tiger", "rabbit", "dragon", 
                   "snake", "horse", "sheep", "monkey",
                   "rooster", "dog", "pig" ,
                  };

int main() {
    int year;
    scanf("%d", &year);
    printf("%s\n", animal[(((year - 1900) % 12 + 12) % 12)]);
    return 0;
}


/*************************************************************************
	> File Name: 1.vector.c
	> Author: 任博宇 
	> Mail: renboyu@hrbeu.edu.cn / renboyu2333@gmail.com
	> Created Time: 三 11/17 11:02:25 2021
 ************************************************************************/
 //将数组封装到Vector里

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct Vector {
    int *data;
    int size, length;
} Vector;

Vector *init(int n) {
    Vector *vec = (Vector *)malloc(sizeof(Vector));
    vec->data = (int *)malloc(sizeof(int) * n);
    vec->size = n;
    vec->length = 0;
    return vec;
}

int expand(Vector *vec) {
    // malloc & calloc & realloc 区别
    // realloc 申请成功 会先销毁之前的空间 返回申请的新空间的首地址
    // realloc讲解: 
    // 比如我们要对*p指向的空间realloc
    // realloc会先尝试在原来的空间后面开辟连续的空间
    // 如果不够 就开辟新的空间 并且把原来的数据拷贝过去
    // 最后free掉原来的空间 不管是malloc还是kalloc的
    // 如果新的空间还不够 就返回一个空地址
    // 并且不动原来的空间
    int new_size = vec->size * 2;
    // vec->data = (int *)realloc(vec->data, sizeof(int) * vec->size);
    //所以我们这段代码在realloc失败的时候 返回了空地址 造成了内存泄漏 找不到之前的地址了!
    int *p = (int *)realloc(vec->data, sizeof(int) * new_size);
    if (p == NULL) return 0;
    vec->size = new_size;
    vec->data = p;
    return 1;
}

int insert(Vector *vec, int ind, int val) {
    if (vec == NULL) return 0;
    if (vec->length == vec->size) {
        if (!expand(vec)) return 0;
        printf("expand vector size to %d success!\n", vec->size);
    }
    if (ind > vec->length || ind < 0) return 0;
    //先判断插入是否合法
    for (int i = vec->length; i > ind; i--) {
        vec->data[i] = vec->data[i - 1];
    }
    vec->data[ind] = val;
    vec->length += 1;
    return 1;
}

int erease(Vector *vec, int ind) {
    if (vec == NULL) return 0;
    if (vec->length == 0) return 0;
    if (ind < 0 || ind >= vec->length) return 0; //因为是从0存到n-1的 数组存
    for (int i = ind; i < vec->length + 1; i++) {
        vec->data[i] = vec->data[i + 1];
    }
    vec->length -= 1;
    return 1;
}

void clear(Vector *vec) {
    if (vec == NULL) return ;
    free(vec->data);
    free(vec);
    return ;
}

void output(Vector *vec) {
    printf("Vector(%d) = [", vec->length);
    for (int i = 0; i < vec->length; i++) {
        if (i) printf(", ");
        printf("%d", vec->data[i]);
    }
    printf("]\n");
}

int main() {
    srand(time(0));
    #define MAX_OP 20
    Vector * vec = init(1);
    int op, ind, val;
    for (int i = 0; i < 20; i++) {
        op = rand() % 4;
        ind = rand() % (vec->length + 1);
        val = rand() % 100;
        switch (op) {
            case 2:
            case 3:
            case 0: {
                printf("insert %d at %d to Vector = %d\n", val, ind, insert(vec, ind, val));
            } break;
            case 1: {
                printf("erease item[%d] from Vector = %d\n", ind, erease(vec, ind));
            } break;
        }
        output(vec);
    }
    return 0;
}

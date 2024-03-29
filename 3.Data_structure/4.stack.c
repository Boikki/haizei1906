/*************************************************************************
	> File Name: 4.stack.c
	> Author: 任博宇 
	> Mail: renboyu@hrbeu.edu.cn / renboyu2333@gmail.com
	> Created Time: Mon Nov 22 10:44:56 2021
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Stack {
    int *data;
    int top, size;
} Stack;

Stack *init(int n) {
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->data = (int *)malloc(sizeof(int) * n);
    s->size = n;
    s->top = -1;
    return s;
}

int empty(Stack *s) {
    return (s->top == -1);
} 

int top(Stack *s) {
    if (empty(s)) return 0;
    return s->data[s->top];
}

int push(Stack *s, int val) {
    if (s == NULL) return 0;
    if (s->top + 1 == s->size) return 0;
    s->top += 1;
    s->data[s->top] = val;
    return 1;
}

int pop(Stack *s) {
    if (s == NULL) return 0;
    if (empty(s)) return 0;
    s->top -= 1;
    //不用清空data[top] 的值！-1操作之后它自己就没了
    return 1;
}

void clear(Stack *s) {
    if (s == NULL) return ;
    free(s->data);
    free(s);
    return ;
}

int output(Stack *s) {
    printf("Stack(%d) = [", s->top + 1);
    for (int i = s->top; i > -1; i--) {
        printf(" %d", s->data[i]);
    }
    printf("]\n");
    return 1;
}


int main() {
    #define MAX_OP 20
    srand(time(0));
    Stack *s = init(MAX_OP);
    for (int i = 0; i < MAX_OP; i++) {
        int op = rand() % 3, val = rand() % 100;
        switch (op) {
            case 0 : 
            case 1 : printf("push %d at %d to Stack = %d\n", val, s->top, push(s, val));
            break;
            case 2: printf("pop %d at %d to Stack = %d\n", top(s), s->top, pop(s));
            break;
        }
        output(s);
    }
    return 0;
}

/*************************************************************************
	> File Name: 3.queue.c
	> Author: 任博宇 
	> Mail: renboyu@hrbeu.edu.cn / renboyu2333@gmail.com
	> Created Time: Mon Nov 22 09:58:37 2021
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Queue {
    int *data;
    int head, tail, length;
    int cnt;
    //cnt 记录队列元素的个数
} Queue;

Queue *init(int n) {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->data = (int *)malloc(sizeof(int) * n);
    q->head = q->tail = q->cnt = 0;
    q->length = n;
    return q;
}

int empty(Queue *q) {
    return (q->cnt == 0);
}

int front(Queue *q) {
    return (q->data[q->head]);
}

int push(Queue *q, int val) {
    if (q == NULL) return 0;
    if (q->cnt == q->length) return 0;
    q->data[q->tail++] = val;
    if (q->tail >= q->length) q->tail -= q->length;
    q->cnt += 1;
    return 1;
}
int pop(Queue *q) {
    if (q == NULL) return 0;
    if (empty(q)) return 0;
    q->head++;
    if (q->head >= q->length) q->head -= q->length;
    q->cnt -= 1;
    return 1;
}

void clrear(Queue *q) {
    if (q == NULL) return ;
    free(q->data);
    free(q);
    return ;
}
void output(Queue *q) {
    printf("Queue = [");
    for (int i = q->head, j = 0; j < q->cnt; j++) {
        int ind = (i + j) % q->length;
        printf(" %d", q->data[ind]);
    }
    printf("]\n");
    printf("Queue = [");
    for (int i = 0; i < q->length; i++) {
        printf(" %d", q->data[i]);
    }
    printf("]\n");

    return ;
}


int main() {
    #define MAX_OP 20
    srand(time(0));
    Queue *q = init(MAX_OP);
    for (int i = 0; i < MAX_OP; i++) {
        int val = rand() % 100, op = rand() % 3;
        switch (op) {
            case 0 : 
            case 1 : printf("push %d at %d to Queue = %d\n", val, q->tail, push(q, val));
            break;
            case 2: printf("pop %d at %d from Queue = %d\n", front(q), q->head, pop(q));
        }
        output(q);
    }
    printf("\n head : %d, tail : %d, cnt : %d\n", q->head, q->tail, q->cnt);
    for (int i = 0; i < MAX_OP; i++) {
        int val = rand() % 100;
        printf("push %d at %d to Queue = %d\n", val, q->tail, push(q, val));
        output(q);
    }
    return 0;
}



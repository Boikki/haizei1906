/*************************************************************************
	> File Name: EP14.c
	> Author: 任博宇 
	> Mail: renboyu@hrbeu.edu.cn / renboyu2333@gmail.com
	> Created Time: 三 11/10 10:33:59 2021
 ************************************************************************/

#include <stdio.h>
#include <inttypes.h>

#define MAX_N 6000000
//这里有一个问题：我减小记忆的数组大小，肯定是会增大时间成本。
//但是我增大数组到10 000 000 怎么 时间还变慢了呢
//这就涉及到CPU的层次体系:
    //CPU -> cache -> memory
    //其中cache又分为L1, L2, L3等 像我的M1就有4个192 KB指令缓存和128 KB数据缓存 并共享12 MB二级缓存
    //四个低功耗核心均有128 KB指令缓存和64 KB数据缓存 
    //当cache存不下这么多的数据的时候 就要进行页面置换 从memory中交换页面自然就增大了时间成本

int f[MAX_N + 5];
int get_chain_length(int64_t x) {
    if (x == 1) return 1;
    if (x <= MAX_N && f[x] != 0) return f[x]; //这一步就实现了记忆
    int ret;
    if (x & 1) ret = get_chain_length(x * 3 + 1) + 1;
    else ret = get_chain_length(x / 2) + 1;
    if (x <= MAX_N) f[x] = ret;
    return ret;
}

int main() {
    int64_t max_len = 0, num = 0;
    for (int64_t i = 1; i < 1000000; i++) {
        int64_t len = get_chain_length(i);
        if (len > max_len) max_len = len, num = i;
    }
    printf("%" PRId64, num);
    return 0;
}

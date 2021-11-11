/*************************************************************************
	> File Name: EP14.c
	> Author: 任博宇 
	> Mail: renboyu@hrbeu.edu.cn / renboyu2333@gmail.com
	> Created Time: 三 11/10 10:33:59 2021
 ************************************************************************/

#include <stdio.h>
#include <inttypes.h>

//暴力法
//

int get_chain_length(int64_t x) {
    if (x == 1) return 1;
    if (x & 1) return get_chain_length(3 * x + 1) + 1;
    return get_chain_length(x / 2) + 1;
}
//段错误了,为啥会这样呢？
//我们看到其实x * 3很可能导致int32不够存的，按100w来算，数可以轻松超过300w
//不妨用两行来判断
//if (x < 0) printf("ERROR\n");
int main() {
    int64_t max_len = 0, num = 0;
    for (int64_t i = 1; i < 1000000; i++) {
        int64_t len = get_chain_length(i);
        if (len > max_len) max_len = len, num = i;
    }
    printf("%" PRId64, num);
    return 0;
}

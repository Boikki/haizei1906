/*************************************************************************
	> File Name: EP44.c
	> Author: 任博宇 
	> Mail: renboyu@hrbeu.edu.cn / renboyu2333@gmail.com
	> Created Time: 日 11/14 15:13:28 2021
 ************************************************************************/

#include <stdio.h>
#include <inttypes.h>

#define MAX_N 0x7fffffffffffffffLL

int64_t pentagonal(int64_t n) {
    return n * (3 * n - 1) >> 1;
}

int64_t binary_search(int64_t (*func)(int64_t), int64_t n, int64_t x) {
    int64_t head = 1, tail = n, mid;
    while(head <= tail) {
        mid = (head + tail) >> 1;
        if (func(mid) == x) return mid;
        if (func(mid) < x) head = mid + 1;
        else tail = mid - 1;
    }
    return 0;
}

int main() {
    int64_t D = MAX_N;
    int64_t pk, pj, n = 2;
    // 这里的终止条件是个问题
    // 我们需要找的是pk, pj的和与差都是pentagonal数并且pk - pj最小(j < k)
    // 也就是pk， pj不止一组，我们找差最小的. 不妨设pk - pj = D
    // 这时候我们就想了:
    // pentagonal(n) - pentagonal(n - 1) 这两项之间的差值是一定会随着n的增大而增大的
    // 所以当有一个D, 若pk - p(k - 1) > D. 那么D一定为我们寻找的最小值, 因为再迭代下去的话
    // 往前走都只能比这个值大了, 因为你的j不能再是p - 1了
    // 往后走这两项之间的差值是一定会随着k的增大而增大的
    //
    while (pentagonal(n) - pentagonal(n - 1) < D) {
        pk = pentagonal(n);
        for (int j = n - 1; j >= 1; j--) {
            pj = pentagonal(j);
            if (pk - pj >= D) break;
            int64_t ind1 = binary_search(pentagonal, n << 1, pk + pj);
            int64_t ind2 = binary_search(pentagonal, n, pk - pj);
            if (ind1 && ind2) D = pk - pj;
        }
        n++;
    }
    printf("%" PRId64 "\n", D);
    return 0;
}

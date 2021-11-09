/*************************************************************************
    > File Name: 6.my_printf.c
    > Author: Boyu Ren
    > Mail: renboyu2333@gmail.com
    > Created Time: Wed 01 Sep 2021 10:48:44 AM CST
 ************************************************************************/

#include <stdio.h>
#include <inttypes.h>
#include <stdarg.h>

int reverse_num(int num, int *temp) {
    int digit = 0;
    *temp = 0;
    do {
        *temp = *temp * 10 + num % 10;
        num /= 10;
        digit += 1;
    } while(num);
    return digit;
}

int out_put_num_with_digit(int num, int digit) {
    int ret = 0;
    while (digit--) {
        putchar(num % 10 + '0');
        num /= 10;
        ret += 1;
    }
    return ret;
}



int my_printf(const char *frm, ...) {
    va_list arg;
    va_start(arg, frm);
    int cnt = 0;
    #define PUTC(a) putchar(a), ++cnt;
    for (int i = 0; frm[i]; i++) {
        switch (frm[i]) {
            case '%': {
                switch (frm[++i]) {
                    case '%' : PUTC(frm[i]); break;
                    //两个%%只输出第一个
                    case 'd' : {
                        int xx = va_arg(arg, int), temp = 0, digit = 0;
                        //digit用来记录位数，防止1000倒过来之后0001这种只会输出一个1
                        uint32_t x;
                        //这里新建了一个xx来存，目的是将INT32_MIN的值存下来。我们知道有符号整形负数比正数多一个
                        //比如：000 111 110 101 100 001 010 011
                        //所以负数取负号之后还是他本身。为了能取到正数，我们用一个无符号整形来中转。
                        if (xx < 0) {
                            PUTC('-');
                            x = -xx;
                        } else x = xx;//处理负数
                        int val1 = x / 100000, val2 = x % 100000;
                        int temp1 = 0, temp2 = 0;
                        int digit1 = reverse_num(val1, &temp1);
                        int digit2 = reverse_num(val2, &temp2); // reverse_num将数字反转，并且存下数字位数。
                        //因为我们的程序逻辑是将数字进行反转再PUTC输出。
                        //但是将INT32_MAX反转之后，32位INT型存不下了。
                        //所以我们将其高五位和低五位分别处理。
                        if (val1) digit2 = 5;
                        else digit1 = 0;
                        cnt += out_put_num_with_digit(temp1, digit1);
                        cnt += out_put_num_with_digit(temp2, digit2);
                        /*
                         * do { 
                            //这里原来是while，被我们改成了do while，因为在输出0的时候。
                            //while(0) 程序就直接不进行任何动作了。但是do while无论如何都会进行一次。
                            temp = x % 10 + temp * 10;
                            x /= 10;
                            digit++;
                        } while(x);
                        while (digit--) {
                            PUTC(temp % 10 + 48);
                            temp /= 10;
                        }
                        */
                    } break;
                    case 's': {
                        const char *str = va_arg(arg, const char *);
                        for (int i = 0; str[i]; i++) {
                            PUTC(str[i]);
                        }
                    }
                    
                }
            } break;
            default : PUTC(frm[i]); break;
        }
    }
    #undef PUTC
    va_end(arg);
    return cnt; //和printf函数一样，我们的printf函数返回值也是位数。
}

int main() {
    int a = 123;
    char str[100] = "I love money";
    my_printf("hello world\n");
    printf("hello world\n");
    my_printf("%d\n", a);
    printf("%d\n", a);

    printf("int(1000) = %d\n", 1000);
    my_printf("int(1000) = %d\n", 1000);
    printf("int(0) = %d\n", 0);
    my_printf("int(0) = %d\n", 0);
    printf("int(-123) = %d\n", -123);
    my_printf("int(-123) = %d\n", -123);
    printf("INT32_MAX = %d\n", INT32_MAX);
    my_printf("INT32_MAX = %d\n", INT32_MAX);
    printf("INT32_MIN = %d\n", INT32_MIN);
    my_printf("INT32_MIN = %d\n", INT32_MIN);
    printf("str = %s\n", str);
    my_printf("str = %s\n", str);
    printf("num = %d\n", printf("%d\n", 123));
    my_printf("num = %d\n", my_printf("%d\n", 123));

    return 0;
}

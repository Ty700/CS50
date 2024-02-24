#include <stdio.h>
#include <stdint.h>

uint32_t sum_of_digits(int n){
    if(n == 0){
        return 0;
    } else {
        return n + sum_of_digits(n - 1);
    }
}

int main(void){
    uint32_t n = 10;
    printf("%d + %d + ... + 0 = %d\n",n, n-1, sum_of_digits(10));
}
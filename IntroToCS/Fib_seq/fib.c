#include <stdio.h>
#include <stdint.h>

uint32_t fib(int n){
    if(n == 1){
        return 0;
    }

    if(n == 2){
        return 1;
    }

    return fib(n - 1) + fib(n - 2);
}

int main(void){
    printf("%dth Fib Number: %d\n", 5, fib(5));
}
#include <stdio.h>
#include <stdint.h>


uint32_t collatz_conjecture(int n){
    static uint32_t steps = 0;

    if(n == 1){
        return steps;
    }      

    steps += 1;

    if(n % 2 == 0){
        //Can do:
        //return 1 + collatz_conjecture(n/2);
        //have to rm steps and make it return 0 if n == 1
        collatz_conjecture(n/2);
    } else {
        //Can do:
        //return 1 + collatz_conjecture(n/2);
        //have to rm steps and make it return 0 if n == 1
        collatz_conjecture(3 * n + 1);
    }
}



int main(void){

    printf("%d\n", collatz_conjecture(7));
    return 0;
}
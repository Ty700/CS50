#include <stdio.h>
#include <stdint.h>

uint32_t powerof(int n, int power){
	if(power == 0){
		return 1;
	} else {
		return n * powerof(n, (power - 1)); 
	}
}

int main(void){
	printf("%d ^ %d = %d\n", 10, 2, powerof(10, 2));
}

#include <stdio.h>
#include <stdint.h>

#define SIZE 500
#define bool uint32_t
#define TRUE   1
#define FALSE 0

int32_t recursive_binary_search(uint32_t array[], uint32_t top, uint32_t bot, uint32_t num_to_find){
    static uint32_t search_count = 0;

    uint32_t index = (top + bot) / 2;

    if(num_to_find == array[index]){
        uint32_t prev_count = search_count;
        search_count = 0;
        return prev_count;
    }

    if(bot > top){
        return -1;
    }

    search_count++;

    if(array[index] > num_to_find){
        recursive_binary_search(array, index, bot, num_to_find);
    } else {
        recursive_binary_search(array, top, index, num_to_find);
    }
}

int32_t binary_search(uint32_t array[], uint32_t arr_size, uint32_t num_to_find){
    if((num_to_find > array[arr_size - 1] || num_to_find < array[0])){
        return -1;
    }

    return recursive_binary_search(array, array[arr_size], array[0], num_to_find);
}

void fill_array(uint32_t size, uint32_t arr[]){
    for(uint32_t i = 0; i <= SIZE; i++){
        arr[i] = i;
    }
}

void find_num(uint32_t arr[], uint32_t arr_size){
    for(int i = 0; i < arr_size; i++){
        printf("Found %d in %d searches\n", arr[i], binary_search(arr, arr_size, arr[i]));
    }
}

int main(void){
    uint32_t arr[SIZE];
    
    fill_array(SIZE, arr);
    
    find_num(arr, SIZE);

}
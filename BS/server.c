#include"server.h"
void generate_array(int arr[]){
    int i;
    for(i = 0; i < SIZE; i++){
        arr[i] = rand();
    }
}

void swap(int *n1, int *n2){
    int temp;
    temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

void bubble_sort(int arr[]){
    int  if_swap;
    comp = 0;
    do{
        if_swap = 0;
        for(int i = 0; i < SIZE - 1; i++){
            if(arr[i] > arr[i + 1]){
                swap(&arr[i], &arr[i + 1]);
                if_swap = 1;
            }
            comp++;
        }
    }while(if_swap);
}
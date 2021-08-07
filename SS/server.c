#include"server.h"
void generate_array(int arr[]){
    for(int i = 0; i < SIZE; i++){
        arr[i] = rand();
    }
}

void swap(int *n1, int *n2){
    int temp;
    temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

void selection_sort(int arr[]){
    int min;
    comp=0;
    for(int i=0;i<SIZE-1;i++){
        min=i;
        for(int j=i+1;j<SIZE;j++){
            if(arr[j]<arr[min])
            {
                min=j;
                swap(&arr[min],&arr[i]);
            }
            comp++;
        }
    }
}
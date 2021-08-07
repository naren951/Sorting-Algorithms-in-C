#include"server.h"
void generate_array(int arr[]){
    int i;
    for(i = 0; i < SIZE; i++){
        arr[i] = rand();
    }
    comp=0;
}

void swap(int *n1, int *n2){
    int temp;
    temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}
int partition (int arr[], int low, int high) 
{ 
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high- 1; j++) 
    {
        if (arr[j] < pivot) 
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
        comp++;
    }
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
}
void quick_sort(int arr[],int low,int high){
    if (low < high) 
    {
        int partition_index = partition(arr, low, high);
        quick_sort(arr, low, partition_index - 1);
        quick_sort(arr, partition_index + 1, high);
    }
}
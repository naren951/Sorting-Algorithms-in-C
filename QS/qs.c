#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 1000000

unsigned long long int comp=0;

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

void main(){
    int *arr = malloc(sizeof(int) * SIZE);
	clock_t start, end;
	double cpu_time_used;
    srand(SIZE);
    generate_array(arr);
	start = clock();
    quick_sort(arr,0,SIZE-1);
	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Number of comparisons: %llu\n", comp);
	printf("Execution time: %lf\n", cpu_time_used);
	FILE *f = fopen("size_vs_comparison.txt", "a");
	fprintf(f, "%d,%llu\n", SIZE, comp);
	fclose(f);
	f = fopen("size_vs_exec_time.txt", "a");
	fprintf(f, "%d,%lf\n", SIZE, cpu_time_used);
	fclose(f);
}
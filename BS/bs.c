#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 1000000

unsigned long long int comp;

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

void main(){
    int *arr = malloc(sizeof(int) * SIZE);
	clock_t start, end;
	double cpu_time_used;
    srand(SIZE);
    generate_array(arr);
	start = clock();
    bubble_sort(arr);
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
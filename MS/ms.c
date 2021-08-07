#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 1000000

unsigned long long int comp=0;
void printArray(int A[])
{
    int i;
    for (i = 0; i < SIZE; i++)
        printf("%d ", A[i]);
    printf("\n");
}

void generate_array(int arr[]){
    int i;
    for(i = 0; i < SIZE; i++){
        arr[i] = rand();
    }
}

void merge(int arr[],int l,int m,int r){
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int left_array[n1], right_array[n2];

    for (i = 0; i < n1; i++)
        left_array[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        right_array[j] = arr[m + 1 + j];
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (left_array[i] <= right_array[j]) {
            arr[k] = left_array[i];
            i++;
        }
        else {
            arr[k] = right_array[j];
            j++;
        }
        k++;
        comp++;
    }
    while (i < n1) {
        arr[k] = left_array[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = right_array[j];
        j++;
        k++;
    }
}

void merge_sort(int arr[], int l, int r)
{
    if (l < r) {
        int m = l + (r - l) / 2;
        merge_sort(arr, l, m);
        merge_sort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}
void main(){
    int *arr = malloc(sizeof(int) * SIZE);
    clock_t start, end;
	double cpu_time_used;
    srand(SIZE);
    generate_array(arr);
	start = clock();
    merge_sort(arr,0,SIZE-1);
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
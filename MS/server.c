#include"server.h"
void generate_array(int arr[]){
    int i;
    for(i = 0; i < SIZE; i++){
        arr[i] = rand();
    }
    comp=0;
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
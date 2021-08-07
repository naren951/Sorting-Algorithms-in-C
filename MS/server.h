#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 100
unsigned long long int comp;
void generate_array(int arr[]);
void merge(int arr[],int l,int m,int r);
void merge_sort(int arr[], int l, int r);
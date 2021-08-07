#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 100

unsigned long long int comp;

void generate_array(int arr[]);
void swap(int *n1, int *n2);
int partition (int arr[], int low, int high);
void quick_sort(int arr[],int low,int high);
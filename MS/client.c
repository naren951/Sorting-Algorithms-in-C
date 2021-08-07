#include"server.h"
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
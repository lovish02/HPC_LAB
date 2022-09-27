#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#define N 100
int main() {
    int *a = (int *)malloc(sizeof(int) * N);
    int *c = (int *)malloc(sizeof(int) * N);
    int b = 10;
    omp_set_num_threads(4);
    for (int i = 0; i < N; i++) {
        a[i] = 0;
    }
    double itime, ftime, exec_time;
    itime = omp_get_wtime();
#pragma omp parallel for schedule(static, 2)
    for (int i = 0; i < N; i++) {
        c[i] = a[i] + b;
        printf("%d by %d\n", i, omp_get_thread_num());
    }
    ftime = omp_get_wtime();
    exec_time = ftime - itime;
    printf("\n\nTime taken is %f\n", exec_time);
}

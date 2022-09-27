#include <stdio.h>
#include<time.h>
#include <omp.h>

int main()
{
    double start;
    double end;
    start = omp_get_wtime();

    int sum = 0;
    #pragma omp parallel for reduction(+ : sum)
    for (int i = 1; i <= 100; i++)
    {
        sum = sum + (i * i);
        printf("The square of %d is %d and Thread id : %d\n",i, i*i,omp_get_thread_num());
    }
    end = omp_get_wtime();
    printf("\n Time taken : %f\n",end-start);
    printf("\n Sum : %d\n", sum);
    return 0;
}

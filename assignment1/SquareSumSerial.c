#include<stdio.h>
#include <omp.h>

int main()
{
    int sum = 0;
    double start,end;

    start = omp_get_wtime();
    for(int i=0;i<100;i++)
    {
        int val = (i + 1) * (i + 1);
        printf("The square of %d is %d and Thread id : %d\n",i, val,omp_get_thread_num());
        sum = sum + val;
    }

    end = omp_get_wtime();
    printf("\n Time taken : %f\n",end-start);
    printf("\n Sum : %d\n", sum);

    return 0;
}

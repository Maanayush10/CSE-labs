//use -lm argument while compiling using gcc
//MPI C program to calculate input raised to the power rank
#include "mpi.h"
#include <stdio.h>
#include <math.h>
int main(int argc, char *argv[])
{
    int rank, size;
    int x;

    printf("Enter the value of x :\t");
    scanf("%d", &x);

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    double answer= pow(x, rank);
    printf("\nMy rank is %d and my power is %f", rank, answer);
    MPI_Finalize();
    
    return 0;
}



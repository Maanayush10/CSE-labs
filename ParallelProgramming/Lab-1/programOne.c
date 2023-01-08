//use -lm argument while compiling using gcc
//MPI C program to calculate input raised to the power rank
#include "mpi.h"
#include <stdio.h>
#include <math.h>
int main(int argc, char *argv[])
{
    int rank, size;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    double answer= pow(3, rank);
    printf("\nMy rank is %d and my power is %f", rank, answer);
    MPI_Finalize();
    
    return 0;
}



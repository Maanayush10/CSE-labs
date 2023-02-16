#include <stdio.h>
#include "mpi.h"

int main(int argc, char *argv[])
{
    int size, rank, N;
    char str1[100], str2[100], c, d;
    char str3[200];
    char join[4];

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (rank == 0)
    {
        N = size;
        printf("Enter the string (Evenly divisible by N) :\t");
        scanf("%s", str1);
        printf("Enter the string (Evenly divisible by N) :\t");
        scanf("%s", str2);
    }
    MPI_Scatter(str1, 1, MPI_CHAR, &c, 1, MPI_CHAR, 0, MPI_COMM_WORLD);
    MPI_Scatter(str2, 1, MPI_CHAR, &d, 1, MPI_CHAR, 0, MPI_COMM_WORLD);

    join[0]=c;
    join[1]=d;
    
    MPI_Gather(join, 2, MPI_CHAR, str3, 2,MPI_CHAR, 0, MPI_COMM_WORLD);
    
    if (rank == 0)
    {
        printf("String obtained: %s\t", str3);
    }
    printf("\n");
    MPI_Finalize();
    return 0;
}
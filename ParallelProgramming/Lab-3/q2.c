#include "mpi.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
    int size, rank, N, M;
    int avg = 0, avgMain = 0;
    int A[100], c[100], i;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (rank == 0)
    {
        N=size;
        printf("Enter the value of M :\t");
        scanf("%d", &M);
        printf("Enter the elements :\t");
        for (i = 0; i < N * M; i++)
        {
            scanf("%d", &A[i]);
        }
    }
    MPI_Bcast(&M, 1, MPI_INT, 0, MPI_COMM_WORLD);

    MPI_Scatter(&A, M, MPI_INT, &c, M, MPI_INT, 0, MPI_COMM_WORLD);
    printf("\n********************************************************\n");
    for (int k = 0; k < M; k++)
    {
        printf("Process:%d,  Element: %d\n", rank, c[k]);
    }
    printf("\n********************************************************\n");

    for (int j = 0; j < M; j++)
    {
        avg = avg + c[j];
    }
    avg = avg / M;

    MPI_Reduce(&avg, &avgMain, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
    if (rank == 0)
    {
        printf("The sum of all averages : %d\n", avgMain);
        avgMain = avgMain / N;
        printf("Final average : %d\n", avgMain);
    }
    MPI_Finalize();
    return 0;
}
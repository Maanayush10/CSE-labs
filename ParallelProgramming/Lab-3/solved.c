#include "mpi.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
    int size, rank, N;
    int A[10], B[10], c, i;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (rank == 0)
    {
        N = size;
        printf("Enter %d elements of the array:\t", N);
        for (int i = 0; i < N; i++)
        {
            /* code */
            scanf("%d", &A[i]);
        }
    }

    MPI_Scatter(A, 1, MPI_INT, &c, 1, MPI_INT, 0, MPI_COMM_WORLD);
    printf("\n[Process :%d] I have received %d\n", rank, c);
    c=c*c;

    MPI_Gather( &c, 1, MPI_INT, B, 1, MPI_INT, 0, MPI_COMM_WORLD);

      if (rank == 0)
    {
        N = size;
        printf("Array elements after being squared :\t");
        for (int i = 0; i < N; i++)
        {
            /* code */
            printf("%d ", B[i]);
        }
    }
    MPI_Finalize();
    return 0;
}
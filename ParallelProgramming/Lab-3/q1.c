#include <stdio.h>
#include "mpi.h"

int fact(int num)
{
    if (num < 2)
    {
        return 1;
    }
    return num * fact(num - 1);
}
int main(int argc, char *argv[])
{
    int rank, size, c;
    int arr[100];
    int B[100];
    int factNum = 1, factSum = 0;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    if (rank == 0)
    {
        printf("Enter array values: \t");
        for (int i = 0; i < size; i++)
        {
            /* code */
            scanf("%d", &arr[i]);
        }
    }
    MPI_Scatter(arr, 1, MPI_INT, &c, 1, MPI_INT, 0, MPI_COMM_WORLD);

    factNum = fact(c);
    printf("[process: %d] fact = %d\n", rank, factNum);

    MPI_Gather(&factNum, 1, MPI_INT, B, 1, MPI_INT, 0, MPI_COMM_WORLD);

    if (rank == 0)
    {
        printf("\n");
        for (int i = 0; i < size; i++)
        {
            printf("%d ", B[i]);
        }
        printf("\n");
        for (int i = 0; i < size; i++)
        {
            factSum = factSum + B[i];
        }
        printf("Sum of factorials is : %d\n", factSum);
    }
    return 0;
}

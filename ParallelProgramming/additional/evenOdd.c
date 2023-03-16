#include <stdio.h>
#include <math.h>
#include "mpi.h"

int main(int argc, char *argv[])
{
    int rank, size, N, length;
    int countEvn=0, countOdd=0;
    int totalEven=0, totalOdd=0;
    int arr[100];
    int temp[50];
    int result[100];
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if (rank == 0)
    {
        printf("Enter the value of N:\t");
        scanf("%d", &N);
        printf("Enter array elements:\t");
        for (int i = 0; i < N; i++)
        {
            scanf("%d", &arr[i]);
        }
        length = N/size;
    }
    MPI_Bcast(&length, 1, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Scatter(arr, length, MPI_INT, &temp, length, MPI_INT, 0, MPI_COMM_WORLD);
    // countEvn=0; countOdd=0;
    // 1 2            3 4             5 6             7 8 
    for (int i = 0 ;i < length; i++)
    {
        if (temp[i] % 2 == 0)
        {
            temp[i] = 1;
            // countEvn++;
        }
        else
        {
            temp[i] = 0;
            // countOdd++;
        }
    }

    MPI_Gather(temp, length, MPI_INT, result, length, MPI_INT, 0, MPI_COMM_WORLD);
    // MPI_Reduce(&countEvn, &totalEven, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
    // MPI_Reduce(&countOdd, &totalOdd, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
    if (rank == 0)
    {
        printf("New array :\n");
        for (int i = 0; i < N; i++)
        {
            printf("%d ", result[i]);
        }
        for (int i = 0; i < N; i++)
        {
            if(result[i]==1)
            {
                countEvn++;
            }
            else
            {
                countOdd++;
            }
        }
        printf("Total number of even elements : %d\n", countEvn);
        printf("Total number of odd elements : %d\n", countOdd);

    }

    MPI_Finalize();
    return 0;
}
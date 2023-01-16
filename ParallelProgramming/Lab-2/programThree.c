//MPI c program to take input in tthe array in master process and show power

#include <stdio.h>
#include <stdlib.h>
#include "mpi.h"

int findSquare(int x)
{
    return x * x;
}

int findCube(int x)
{
    return x * x * x;
}

int main(int argc, char *argv[])
{
    int size, rank, x, ans;

    MPI_Init(&argc, &argv);

    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int arr[size];

    if (rank == 0)
    {
        printf("Enter array elements :\t");
        for (int i = 1; i < size; i++)
        {
            scanf("%d", &arr[i]);
        }

        int buffer_size = MPI_BSEND_OVERHEAD + sizeof(int)*size-1;
        char *buffer = (char*)malloc(buffer_size);
        MPI_Buffer_attach(buffer, buffer_size);

        for (int j = 0; j < size; j++)
        {
            MPI_Bsend(&arr[j], 1, MPI_INT, j, j, MPI_COMM_WORLD);
        }
        MPI_Buffer_detach(&buffer, &buffer_size);
    }
    else
    {
        MPI_Recv(&x, 1, MPI_INT, 0, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        if (rank % 2 == 0)
        {
            ans = findSquare(x);
        }
        else
        {
            ans = findCube(x);
        }
        printf("\n[Process : %d] Number Sent : %d \t Power :%d\n", rank, x, ans);
    }

    return 0;
}
#include<stdio.h>
#include "mpi.h"
int main(int argc, char * argv[]){
    int rank, size;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    int d[size];
    int arr[size][size];
    int arr2[size][size];


    if (rank == 0)
    {
        printf("Enter array elements :\n");
        for (int i = 0; i < size; i++)
        { // take user i/p
            for (int j = 0; j < size; j++)
            {
                scanf("%d", &arr[i][j]);
            }
        }
    }
    // MPI_Scatter(arr, size, MPI_INT, d, size, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Alltoall(arr, size, MPI_INT, arr2, size, MPI_INT, MPI_COMM_WORLD);
    if (rank == 0)
    {
        printf("\n");
        // printf("Enter array elements :\n");
        for (int i = 0; i < size; i++)
        { // take user i/p
            for (int j = 0; j < size; j++)
            {
                printf("%d", arr2[i][j]);
            }
            
        }
        printf("\n");
    }
return 0;
}
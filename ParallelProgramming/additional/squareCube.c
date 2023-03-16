#include<stdio.h>
#include <math.h>
#include"mpi.h"

int main(int argc, char * argv[]){
    int rank, size, M;
    int arr[100];
    int temp[50];
    int result[100];
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if(rank==0)
    {
        printf("Enter the value of M:\t");
        scanf("%d", &M);

        printf("Enter array elements:\t");
        for(int i=0; i<size; i++)
        {
            scanf("%d", &arr[i]);
        }

    }   

    MPI_Bcast(&M, 1, MPI_INT, 0 , MPI_COMM_WORLD);
    MPI_Scatter(arr, M, MPI_INT, temp, M, MPI_INT, 0, MPI_COMM_WORLD);

    //1 2 3 4       5 6 7 8

    for(int i=0; i<M; i++)
    {
        temp[i]= pow(temp[i], (rank+2));
    }
    MPI_Gather(temp, M, MPI_INT, result, M, MPI_INT, 0, MPI_COMM_WORLD);
    if(rank==0)
    {
        printf("New array :\n");
        for(int i=0; i<size; i++)
        {
            printf("%d ", result[i]);
        }
    }
    MPI_Finalize();
return 0;
}
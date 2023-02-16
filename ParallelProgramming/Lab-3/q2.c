#include"mpi.h"
#include<stdio.h>
int main(int argc, char * argv[])
{
    int size, rank, N, M, i;
    int indAvg=0, finalAvg=0;
    int A[100], c[M];
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if(rank==0)
    {
        N=size;
        printf("Enter the value of M :\t");
        scanf("%d", &M);


        printf("Enter the array elements:\t");

        for(i=0; i<N*M; i++)
        {
            scanf("%d", &A[i]);
        }
    }
    MPI_Bcast(&M, 1, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Scatter(A, M, MPI_INT, c, M, MPI_INT, 0, MPI_COMM_WORLD);
    
    for(i=0; i<M; i++)
    {
        indAvg= indAvg+c[i];
    }
    indAvg= indAvg/M;

    MPI_Reduce(&indAvg, &finalAvg, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

    if(rank==0)
    {
        printf("Sum of all averages : %d\n", finalAvg);
        printf("The final average is : %d \n", (finalAvg/M)); //here noy by M*N because we are finding avgs of avgs i.e. avg_total/ number of indAvgs
    }
    printf("\n");
    MPI_Finalize();
    return 0;
}
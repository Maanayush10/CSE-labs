//MPI C program to send the number to next process, which increments the number and sends it to the next process in sequence.
#include <mpi/mpi.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    int size, rank;

    MPI_Init(&argc, &argv);

    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    int num;
    if (rank == 0)
    {
        printf("Enter an Integer : ");
        scanf("%d", &num);
        MPI_Send(&num, 1, MPI_INT, rank+1, rank+1, MPI_COMM_WORLD);
        MPI_Recv(&num, 1, MPI_INT, size-1, rank, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("[Process :%d]===> [num: %d]\n", rank, num);
    }
    else
    {
        MPI_Recv(&num, 1, MPI_INT, rank-1, rank, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("[Process :%d]===> [num: %d]\n", rank, num);
        num++;
        MPI_Send(&num, 1, MPI_INT, (rank+1)%size, (rank+1)%size, MPI_COMM_WORLD);
    }

    MPI_Finalize();

    return 0;
}

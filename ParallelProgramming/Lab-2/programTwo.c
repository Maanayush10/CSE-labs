//MPI C program to send a number to each of the slave process

#include "mpi.h"
#include <stdio.h>
int main(int argc, char *argv[])
{
    int rank, size, x;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Status status;
    if (rank == 0)
    {
        for(int i=1; i<size; i++)
        {
            MPI_Send(&i, 1, MPI_INT, i, i, MPI_COMM_WORLD);
        }
    }
    else
    {
        MPI_Recv(&x, 1, MPI_INT, 0, rank, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        fprintf(stdout, "[Process : %d]I have received %d in process %d\n", rank, x, rank);
        fflush(stdout);
    }
    MPI_Finalize();
    return 0;
}

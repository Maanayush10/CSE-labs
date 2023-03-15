//I/p :  PCAP 
//O/P :  PCCAAAPPPP
#include<stdio.h>
#include<string.h>
#include "mpi.h"
int main(int argc, char * argv[])
{
    int rank, size, length;
    char c;
    char d[20];

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    char str[size];

    if(rank==0)
    {
        printf("Enter the string :\t");
        scanf("%s", str);
        length = strlen(str);
    }
    MPI_Bcast(&length, 1, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Bcast(str, length, MPI_CHAR, 0, MPI_COMM_WORLD);
    MPI_Barrier(MPI_COMM_WORLD);
    for(int i =0; i<rank+1; i++)
    {
        printf("%c",str[rank]);
    }

    MPI_Finalize();

return 0;
}

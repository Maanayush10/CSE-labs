#include "mpi.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char * argv[])
{
    int rank, size;
    char str1[100];
    char str2[100];

    char recvBuff[200];
    char c, d;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (rank == 0)
    {
        printf("Enter a string1 (Evenly divisible by N) :\t");
        scanf("%s", str1);
        printf("Enter a string2 (Evenly divisible by N) :\t");
        scanf("%s", str2);
    }

    MPI_Scatter(str1, 1, MPI_CHAR, &d, 1, MPI_CHAR, 0, MPI_COMM_WORLD);
    MPI_Scatter(str2, 1, MPI_CHAR, &c, 1, MPI_CHAR, 0, MPI_COMM_WORLD);
    printf("\n");
    printf("[process : %d], Letter : %c\n", rank, c);
    printf("[process : %d], Letter : %c", rank, d);
    printf("\n");

    MPI_Gather( &c , 1 , MPI_CHAR , &recvBuff , 1 , MPI_CHAR , 0, MPI_COMM_WORLD);
    MPI_Gather( &d , 1 , MPI_CHAR , &recvBuff , 1 , MPI_CHAR , 0, MPI_COMM_WORLD);

    if(rank==0)
    {
        printf("\n*****************************\n");
        printf("\nProcess : %d\n", rank);
        printf("%s", recvBuff);
    }

    MPI_Finalize();

    return 0;
}

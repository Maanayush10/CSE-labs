#include <stdio.h>
#include "mpi.h"
#include <string.h>

int main(int argc, char *argv[])
{
    int rank, size, count = 0, length;
    char str[100];
    char str2[100];
    char temp1[100];
    char temp2[100];

    char result[200];

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if (rank == 0)
    {
        printf("Enter the string 1:\t");
        scanf("%s", str);
        printf("Enter the string 2 :\t");
        scanf("%s", str2);
        length = strlen(str);
        length = length / size;
        printf("hello\n");
    }
    MPI_Bcast(&length, 1, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Scatter(str, length, MPI_CHAR, temp1, length, MPI_CHAR, 0, MPI_COMM_WORLD);
    MPI_Scatter(str2, length, MPI_CHAR, temp2, length, MPI_CHAR, 0, MPI_COMM_WORLD);

    char result2[200];
    result2[0] = '\0';

    int i = 0, j = 0, k = 0;
    // printf("hello\n");
    while (i < length || j < length)
    {
        if (i % 2 == 0)
        {
            result2[k++] = temp1[i++];
        }
        else
        {
            result2[k++] = temp2[j++];
        }
    }
    // printf("hello\n");
    result2[k] = '\0';
    MPI_Gather(result2, 2 * length, MPI_CHAR, result, 2 * length, MPI_CHAR, 0, MPI_COMM_WORLD);
    if (rank == 0)
    {
        printf("The resultant string is : %s\n", result);
    }

    MPI_Finalize();

    return 0;
}
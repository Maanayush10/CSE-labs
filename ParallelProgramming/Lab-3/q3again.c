#include <stdio.h>
#include "mpi.h"
#include <string.h>
int countC = 0;
int checkVowel(char c)
{
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
    {
        return 1;
    }
    return 0;
}

int numOfconsonants(char *str)
{
    int count = 0;
    for (int i = 0; i < strlen(str); i++)
    {
        if (checkVowel(str[i]) != 1)
        {
            count++;
        }
    }
    return count;
}

int main(int argc, char *argv[])
{
    int size, rank, N;
    char str[100], c[20];
    int count = 0, totalCount = 0, div=0;
    int processCount[size];
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (rank == 0)
    {
        N = size;
        printf("Enter the string (Evenly divisible by N) :\t");
        scanf("%s", str);
        div=(strlen(str))/size;
    }
    MPI_Bcast(&div, 1, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Scatter(str, div, MPI_CHAR, c, div, MPI_CHAR, 0, MPI_COMM_WORLD);

    count = numOfconsonants(c);
    printf("[Process : %d] %s has %d consonants\n", rank, c, count);
    MPI_Gather(&count, 1, MPI_INT, processCount, 1, MPI_INT, 0, MPI_COMM_WORLD);

    MPI_Reduce(&count, &totalCount, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

    if (rank == 0)
    {
        printf("The total number of consonants : %d\n", totalCount);
    }
    printf("\n");
    MPI_Finalize();
    return 0;
}
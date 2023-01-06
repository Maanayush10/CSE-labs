//MPI C program to toggle a given string's charecter based on the rank as the index
#include "mpi.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    int rank, size;
    char * arr;
    arr= (char * )malloc(sizeof(char));

    printf("Enter any string :\t");
    scanf("%s", arr);

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);


    char ch= arr[rank];
    if(ch<=90 && ch>=65)
    {
        arr[rank]= tolower(ch);
    }
    if(ch>=97 && ch<=122)
    {
        arr[rank]= toupper(ch);
    }

    printf("%s\n", arr);
    MPI_Finalize();
    
    return 0;
}
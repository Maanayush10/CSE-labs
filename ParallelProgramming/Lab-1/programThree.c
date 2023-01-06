//MPI c program to make a simple calculator

#include "mpi.h"
#include<stdio.h>
int main(int argc, char *argv[]){
    int rank, size;
    int a, b;
    printf("Enter the value of a and b :\t");
    scanf("%d", &a); scanf("%d", &b);

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    switch(rank)
    {
        case 0: 
                printf("Process RANK : %d\n", rank);
                printf("Sum : %d\n", a+b);
                break;
        
        case 1:
                printf("Process RANK : %d\n", rank);
                printf("Difference : %d\n", a-b);
                break;
        case 2: 
                printf("Process RANK : %d\n", rank);
                printf("Product : %d\n", a*b);
                break;
        case 3: 
                printf("Process RANK : %d\n", rank);
                printf("Quotient : %d\n", a/b);
                break;
        default: 
                printf("No process running currently\n");
    }

    MPI_Finalize();
return 0;
}
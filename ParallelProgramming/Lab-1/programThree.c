//MPI c program to make a simple calculator

#include "mpi.h"
#include<stdio.h>
int main(int argc, char *argv[]){
    int rank, size;
    int a=10, b=20;
//     printf("\nValue of a=10 and b=20 \n");

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    switch(rank)
    {
        case 0:
                printf("\n\n");
                printf("Process RANK : %d\n", rank);
                printf("Sum : %d\n", a+b);
                break;
        
        case 1:
                printf("\n\n");
                printf("Process RANK : %d\n", rank);
                printf("Difference : %d\n", a-b);
                break;
        case 2: 
                printf("\n\n");
                printf("Process RANK : %d\n", rank);
                printf("Product : %d\n", a*b);
                break;
        case 3: 
                printf("\n\n");
                printf("Process RANK : %d\n", rank);
                printf("Quotient : %d\n", a/b);
                break;
        default: 
                printf("No process running currently\n");
    }

    MPI_Finalize();
return 0;
}

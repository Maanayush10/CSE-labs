#include<stdio.h>
#include<stdlib.h>
#include"mpi.h"

void ErrorHandler(int err_code){
    if(err_code != MPI_SUCCESS){
        char error_string[BUFSIZ];
        int length_err_string, err_class;
        MPI_Error_class(err_code, &err_class);
        MPI_Error_string(err_code, error_string, &length_err_string);
        fprintf(stderr, "Error: %d %s\n", err_class, error_string);
    }
}


int main(int argc, char * argv[])
{
    int rank, size, fact=1, factsum, i;
    int err_code;

    MPI_Init(&argc, &argv);
    MPI_Errhandler_set(MPI_COMM_WORLD, MPI_ERRORS_RETURN);
    err_code = MPI_Comm_rank(MPI_COMM_WORLD, &rank);
        ErrorHandler(err_code);
    err_code = MPI_Comm_size(MPI_COMM_WORLD, &size);
        ErrorHandler(err_code);
    for(i=1; i<=rank+1; i++)
    {
        fact = fact * i;
    }

    err_code = MPI_Scan(&fact, &factsum, 1, MPI_INT, MPI_SUM, MPI_COMM_WORLD);
    ErrorHandler(err_code);
    if(rank==size-1)
    {
        printf("Sum of all factorial is = %d\n", factsum);
    }
    MPI_Finalize();
    exit(0);
}
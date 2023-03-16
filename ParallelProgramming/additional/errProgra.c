#include <stdio.h>
#include "mpi.h"

void ErrorHandler(int err_code)
{
    if(err_code != MPI_SUCCESS)
    {
        char err_string[100];
        int length_of_err_string, err_class;
        MPI_Error_class(err_code, &err_class);
        MPI_Error_string(err_code, err_string, &length_of_err_string);
    }
}

int main(int argc, char * argv[])
{
    int rank, size, error_code;
    MPI_Init(&argc, &argv);
    MPI_Errhandler_set(MPI_COMM_WORLD, MPI_ERRORS_RETURN);
    error_code =MPI_Comm_size(MPI_COMM_WORLD, &size);
    ErrorHandler(error_code);
    error_code =MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    ErrorHandler(error_code);

    printf("My rank is %d out of %d processes.\n", rank, size);
    MPI_Finalize();
    return 0;
}
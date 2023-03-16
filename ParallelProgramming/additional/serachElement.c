#include <stdio.h>
#include "mpi.h"

void ErrorHandler(int err_code)
{
    if(err_code!=MPI_SUCCESS)
    {
        int length_of_err_string,err_class;
        char err_string[200];
        MPI_Error_class(err_code, &err_class);
        MPI_Error_string(err_code, err_string, &length_of_err_string);
        printf("Error: %s\n", err_string);
    }
}

int main(int argc, char * argv[])
{
    int rank, size, key, count=0, totalC =0, err_code;
    int arr[3][3];
    MPI_Init(&argc, &argv);
    MPI_Errhandler_set(MPI_COMM_WORLD, MPI_ERRORS_RETURN);
    err_code=MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    ErrorHandler(err_code);
    err_code=MPI_Comm_size(MPI_COMM_WORLD, &size);
    ErrorHandler(err_code);
    if(rank==0)
    {
        printf("Enter the elements:\t");
        for (int i = 0; i < 3; i++)
        {
            /* code */
            for (int j = 0; j < 3; j++)
            {
                /* code */
                scanf("%d", &arr[i][j]);
            }
            
        }
        printf("Enter element to be searched :\t");
        scanf("%d", &key);
        
    }
    int arr2[3];
    err_code=MPI_Bcast(&key, 1, MPI_INT, 0, MPI_COMM_WORLD);
    ErrorHandler(err_code);
    err_code=MPI_Scatter(arr, 3, MPI_INT, arr2, 3, MPI_INT, 0, MPI_COMM_WORLD);
    ErrorHandler(err_code);


    printf("\n");
    for (int i = 0; i < 3; i++)
    {
        /* code */
        printf("%d ", arr2[i]);
    }
    printf("\n");
    
    for (int i = 0; i < size; i++)
    {
        /* code */
        if(arr2[i]==key)
        {
            count++;
        }
    }

    err_code=MPI_Reduce(&count, &totalC, 1, MPI_INT, MPI_SUM , 0, MPI_COMM_WORLD);
    ErrorHandler(err_code);
    if(rank==0)
    {
        printf("The total number of occurences of the given key is : %d\n", totalC);
    }
    
    MPI_Finalize();

    return 0;
}
// 2 matrices A,B find min row ele of A and max col ele of B. Add max col ele of B to min row ele of A.
// If min is not principal diagonal ele, put principal diagonal ele=0

#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv[])
{
    int A[4][4] = {{1, 2, 3, 4},
                   {5, 6, 7, 8},
                   {9, 10, 11, 12},
                   {13, 14, 15, 16}};
    int B[4][4] = {{1, 2, 3, 4},
                   {5, 6, 7, 8},
                   {9, 10, 11, 12},
                   {13, 14, 15, 16}};
    int aCol[4], bRow[4];
    int aMin[4], bMax[4];
    int sum[4];

    int rank, size;
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if (rank == 0)
    {
        // printf("Enter matrix A:\n");
        // for(int i=0;i<4;i++)
        // 	for(int j=0;j<4;j++)
        // 		 scanf("%d",&A[i][j]);

        // printf("Enter matrix B:\n");
        // for(int i=0;i<4;i++)
        // 	for(int j=0;j<4;j++)
        // 		scanf("%d",&B[i][j]);
    }

    // A Min of rows
    // B Max of cols


    //transpose
    for (int i = 0; i < 4; i++)
    {
        MPI_Scatter(&A[i], 1, MPI_INT, &aCol[i], 1, MPI_INT, 0, MPI_COMM_WORLD);
        // printf("%d ", aCol[i]);
    }
    printf("\n");

    
    MPI_Reduce(aCol, aMin, 4, MPI_INT, MPI_MIN, 0, MPI_COMM_WORLD);

    MPI_Scatter(B, 4, MPI_INT, bRow, 4, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Reduce(bRow, bMax, 4, MPI_INT, MPI_MAX, 0, MPI_COMM_WORLD);

    if (rank == 0)
    {
        printf("Min A:\n");
        for (int i = 0; i < 4; i++)
            printf("%d\t", aMin[i]);

        printf("\nMax B:\n");
        for (int i = 0; i < 4; i++)
            printf("%d\t", bMax[i]);

        for (int i = 0; i < 4; i++)
            sum[i] = aMin[i] + bMax[i];

        printf("\nSum:\n");
        for (int i = 0; i < 4; i++)
            printf("%d\t", sum[i]);

        printf("\n");

        int k = 0;

        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (A[i][j] == aMin[k])
                    A[i][j] = sum[k++];
            }
        }

        printf("\nModified A:\n");
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
                printf("%d\t", A[i][j]);
            printf("\n");
        }

        k = 0;
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (i == j)
                {
                    if (A[i][j] != sum[k])
                        A[i][j] = 0;
                }
            }
        }

        printf("\nFinal A:\n");
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
                printf("%d\t", A[i][j]);
            printf("\n");
        }
    }

    MPI_Finalize();
    return 0;
}
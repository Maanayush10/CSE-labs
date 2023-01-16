//MPI C program to send a word to another process, get it toggled and return the result

#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void toggle(int size, char *word)
{
	for (int i = 0; i < size; i++)
	{
		if (word[i] <= 90 && word[i] >= 65)
		{
			word[i] = tolower(word[i]);
		}
		else
		{
			word[i] = toupper(word[i]);
		}
	}
}
int main(int argc, char *argv[])
{
	int rank, size, length;
	char *x = (char *)malloc(sizeof(char));
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Status status;
	if (rank == 0)
	{
		printf("Enter a your word in master process:");
		scanf("%s", x);

		length = strlen(x);
		MPI_Ssend(&length, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
		MPI_Ssend(x, length, MPI_CHAR, 1, 1, MPI_COMM_WORLD);
		fprintf(stdout, "[Process 0] word before toggle : %s\n", x);
		MPI_Recv(x, length, MPI_CHAR, 1, 2, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		fprintf(stdout, "Word after toggle : %s\n", x);
		fflush(stdout);
	}
	else
	{
		MPI_Recv(&length, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE );
		MPI_Recv(x, length, MPI_CHAR, 0, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		toggle(length, x);
		MPI_Ssend(x, length, MPI_CHAR, 0, 2, MPI_COMM_WORLD);
		fflush(stdout);
	}
	MPI_Finalize();
	return 0;
}
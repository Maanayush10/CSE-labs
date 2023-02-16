#include "mpi.h"
#include<stdio.h>

int checkVowel(char c)
{
    if(c=='a'|| c=='e'|| c=='i'|| c=='o'|| c=='u'||c=='A'|| c=='E'|| c=='I'|| c=='O'|| c=='U')
    {
        return 1;
    }
    return 0;
}

int main(int argc, char * argv[]){
    int rank, size;
    char str[100];
    char c;
    int count=0, countSum=0;
    MPI_Init( &argc , &argv);
    MPI_Comm_rank(MPI_COMM_WORLD , &rank);
    MPI_Comm_size(MPI_COMM_WORLD , &size);
    
    if(rank ==0)
    {
        printf("Enter a string (Evenly divisible by N) :\t");
        scanf("%s", str);
    }

    MPI_Scatter( &str , 1 , MPI_CHAR , &c , 1 , MPI_CHAR , 0 , MPI_COMM_WORLD);

    printf("\n***************************\n");
    printf("[process : %d] I have recieved %c\n", rank, c);
    if(checkVowel(c))
    {
        printf("%c is a Vowel\n", c);
    }
    else
    {
        printf("%c is NOT a vowel\n", c);
        count++;
    }
    
   MPI_Reduce( &count , &countSum ,1 , MPI_INT , MPI_SUM ,0 , MPI_COMM_WORLD);
    if(rank==0)
    {
        printf("The number of non-Vowels : %d\n", countSum);
    }
    MPI_Finalize();
return 0;
}
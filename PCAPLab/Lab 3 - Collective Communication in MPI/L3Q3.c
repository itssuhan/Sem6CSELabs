// Write a MPI program to read a string. Using N processes (string length is evenly divisible
// by N), find the number of non-vowels in the string. In the root process print number of
// non-vowels found by each process and print the total number of non-vowels.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mpi/mpi.h>

int main(int argc, char *argv[])
{
    int rank,size;
    int N,StringLength;
    int result;
    char *ProcessStringArray;
    char RootStringArray[100];

    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    MPI_Comm_size(MPI_COMM_WORLD,&size);

    if(rank==0)
    {
        N = size;
        printf("Enter the String : \n");
        scanf("%s", RootStringArray);
        StringLength = strlen(RootStringArray)/N;
                                                    // if(StringLength%N!=0)
                                                    // {
                                                    //     printf("Error : StringLength Error ");
                                                    //     MPI_Abort(MPI_COMM_WORLD,1);
                                                    // }
    
    }

  //Broadcast length to other strings
  MPI_Bcast(&StringLength,1,MPI_INT,0,MPI_COMM_WORLD);
  ProcessStringArray = (char *)calloc(StringLength, sizeof(char));
	MPI_Scatter(RootStringArray, StringLength, MPI_CHAR, ProcessStringArray, StringLength, MPI_CHAR, 0, MPI_COMM_WORLD);
	int sendResult = 0;
	for (int i = 0; i < StringLength; i++)
  {
		if (ProcessStringArray[i] == 'a' || ProcessStringArray[i] == 'e' || ProcessStringArray[i] == 'i' || ProcessStringArray[i] == 'o' || ProcessStringArray[i] == 'u' || ProcessStringArray[i] == 'A' || ProcessStringArray[i] == 'E' || ProcessStringArray[i] == 'I' || ProcessStringArray[i] == 'O' || ProcessStringArray[i] == 'U')
			sendResult++;
	}
	sendResult = StringLength - sendResult;
	printf("Process %d has %d non vowels\n",rank,sendResult);
	
	MPI_Reduce(&sendResult, &result, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
	
	if (rank == 0)
  {
		printf("The total non-vowels are : %d\n", result);
  }
  
	free(ProcessStringArray);
	MPI_Finalize();
	return 0;
}

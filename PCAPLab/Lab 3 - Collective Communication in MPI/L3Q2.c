// Write a MPI program to read an integer value M and NxM elements into an 1D array in
// the root process, where N is the number of processes. Root process sends M elements to
// each process. Each process finds average of M elements it receives and sends these average
// values to root. Root collects all the values and finds the total average. Use collective
// communication routines.

#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

int main(int argc, char *argv[])
{
    int rank,size; // For calculating rank and size of the process      
    int M,N;
    int *RootArray = NULL; // Array to hold the N*M elements in the root process
    int *ProcessArray = NULL; // Array to hold Elements from the Root Process
    int RootResult;

    MPI_Init(&argc,&argv); //Initiate
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);  //Find rank
    MPI_Comm_size(MPI_COMM_WORLD,&size);  //Find size

    //Enter root process
    if(rank==0)
    {
        N=size;
        printf("Enter the Value of M (No of Elements)");
        scanf("%d",&M);

        //Allocating memory for the rootarray and read elements into the array
        RootArray = (int *)calloc(N * M, sizeof(int));
        printf("Enter %d elements\n",N*M);
        for(int i=0;i<N*M;i++)
        {
            scanf("%d",&RootArray[i]);
        }
    }

    // MPI_Bcast(&M,1,MPI_INT,0,MPI_COMM_WORLD);

    ProcessArray = (int *)calloc(M,sizeof(int));

    //Scatter the elements from rootArray to ProcessArray

    MPI_Scatter(RootArray,M,MPI_INT,ProcessArray,M,MPI_INT,0,MPI_COMM_WORLD);
    int SendResult = 0;
    for(int i=0;i<M;i++)
    {
        SendResult = SendResult+ProcessArray[i]; //Calculating Sum of each elements
    }

    SendResult = SendResult/M; // Calculating Average

    //Sending Average result to Root Process

    MPI_Reduce(&SendResult,&RootResult,1,MPI_INT,MPI_SUM,0,MPI_COMM_WORLD);

    if(rank==0)
    {
        printf("The Total Average is %d",RootResult/N);
        free(RootArray);
    }

    free(ProcessArray);
    MPI_Finalize();
    return 0;
}

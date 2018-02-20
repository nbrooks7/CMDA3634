#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "mpi.h"


void myMPI_Bcast(int *N, int root){

    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

   //every rank other thank rank 0 receives
   if (rank != root){
    MPI_Status status;
    int tag = 1;

    int sourceRank = rank -1; //receive from previoue rank
    if (rank = 0) sourceRank = size -1; //careful of rank 0

    MPI_Recv(N,  //pointer to int
             1,
             MPI_INT,
             sourceRank,
             tag,
             MPI_COMM_WORLD,
             &status);
    
   }
   
   int prev = root -1;
   if (root ==0) prev = size-1;


   //every rank other than the  previous rank send the data
   if (rank != prev){
    int tag = 1;
    int destRank = rank+1;
    if (rank == size -1) destRank = 0;

    MPI_Send(N,
             1,
             MPI_INT,
             destRank,
             tag,
             MPI_COMM_WORLD);
   }
}

//this acts as a barrier
//no process can leave this function unless all processes have made it this far
void myMPI_Barrier(){
    int N;
    int rank,size;   
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);



    if (rank ==0) N=1; 
    myMPI_Bcast(&N, 0);

    if (rank == size -1) N=10;  
    myMPI_Bcast(&N, size -1);
}



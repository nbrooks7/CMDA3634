#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "mpi.h"


void myMPI_Bcast(int *N, ){

    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

   //every rank other thank rank 0 receives
   if (rank >0){
    MPI_Status status;
    int tag = 1;

    int sourceRank = rank -1; //receive from previoue rank

    MPI_Recv(N,  //pointer to int
             1,
             MPI_INT,
             sourceRank,
             tag,
             MPI_COMM_WORLD,
             &status);
    
   }
   
   //every rank other than the last sent the data
   if (rank< size-1){
    int tag = 1;
    int destRank = rank+1;

    MPI_Send(N,
             1,
             MPI_INT,
             destRank,
             tag,
             MPI_COMM_WORLD);
   }
}


int main(int argc, char **argv){

    MPI_Init(&argc, &argv);

    int rank;   
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    int N;

    if (rank ==0) N=199;  //only eank 0 fils a value

    myMPI_Bcast(&N);


    printf("Rank %d recieved the value N = %d\n", rank, N);

    MPI_Finalize();
    return 0;


}

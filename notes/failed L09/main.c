#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "mpi.h"



int main(int argc, char **argv){

    MPI_Init(&argc, &argv);

    int rank,size;   
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);


    int N;

    if (rank ==0) N=199;  //only eank 0 fils a value

    myMPI_Bcast(&N, 0);
    printf("Rank %d recieved the value N = %d\n", rank, N);
   
    if (rank == size -1) N=10;  //only eank 0 fils a value

    myMPI_Bcast(&N, size -1);
    printf("Rank %d recieved the value N = %d\n", rank, N);

    myMPI_Barrier();

    MPI_Finalize();
    return 0;


}

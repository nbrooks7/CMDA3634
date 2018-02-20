#include "mympi.h"

int main (int argc, char **argv) {

  MPI_Init(&argc,&argv);

  int rank,size;
  MPI_Comm_rank(MPI_COMM_WORLD,&rank);
  MPI_Comm_size(MPI_COMM_WORLD,&size);

  int N;

  if (rank==0) N=199;
  
  //this the actual MPI broadcast function
  MPI_Bcast(&N,          //pointer to data
            1,           // count (number of entries)
            MPI_INT,     //data type
            0,           //root process (the process taht broadcasts)
            MPI_COMM_WORLD);
  printf("Rank %d recieved the value N = %d\n",rank,N);

  //myMPI_Bcast(&N,0);
  treeMPI_Bcast(&N);
  printf("Rank %d recieved the value N = %d\n",rank,N);

  if (rank==size-1) N=10;

  MPI_Bcast(&N,          //pointer to data
            1,           // count (number of entries)
            MPI_INT,     //data type
            size -1,           //root process (the process taht broadcasts)
            MPI_COMM_WORLD);
  printf("Rank %d recieved the value N = %d\n",rank,N);

  myMPI_Barrier();

  //setup a test for the reduction
  float val = 1.0;

  //MPI's reduce function
  MPI_Reduce(&val,      //send buffer
             &sum,      //receive buffer
             1,         //count
             MPI_FLOAT,   //data type
             MPI_SUM,   // operation - others are MPI_MIN, MPI_MAX, MPI_PROD
             0,         // root process (the one that has the final answer)
             MPI_COMM_WORLD); //communicator

  for (int r=0;r<size;r++) {
    if (r==rank) {
      printf("Rank %d has value %f after the reduction.\n", rank, sum);
    }
    myMPI_Barrier(MPI_COMM_WORLD); 
  }

  MPI_ALLreduce(&val,
                &sum,
                1,
                MPI_FLOAT,
                MPI_SUM,
                MPI_COMM_WORLD);

  for (int r=0;r<size;r++) {
    if (r==rank) {
      printf("Rank %d has value %f after the reduction.\n", rank, sum);
    }
    myMPI_Barrier(MPI_COMM_WORLD); 
  }

  MPI_Finalize();
  return 0;
}

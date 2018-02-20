#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "mpi.h"


void myMPI_Bcast(int *N, int root);
//this acts as a barrier
//no process can leave this function unless all processes have made it this far
void myMPI_Barrier();

void trrMPI_Bcast(int *N);

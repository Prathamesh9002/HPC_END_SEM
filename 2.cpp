#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char ** argv)
{
       float * array;
       int tag=1;
       int size;
       int rank;
       MPI_Status status;
       MPI_Init (&argc,&argv);
       MPI_Comm_size (MPI_COMM_WORLD,&size);
       MPI_Comm_rank (MPI_COMM_WORLD,&rank);
       if (rank == 0)
       {
         array=(float*)malloc(10*sizeof(float)); // Array of 10 elements
         if (!array) // error checking
         {
          MPI_Abort (MPI_COMM_WORLD,1);
         }
       MPI_Send(&array,10,MPI_INT,1,tag,MPI_COMM_WORLD);
       }
       if (rank == 1)
       {
        MPI_Recv (&array,10,MPI_INT,0,tag,MPI_COMM_WORLD,&status);
        // more code here
       }
      MPI_Finalize();
}
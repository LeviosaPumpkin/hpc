/*#include "mpi.h"
#include <stdio.h>
#define leng 20 
int main(int argc, char **argv)
{
   int rank, size;
   float a, b, t;
   char     WR[leng]; 
   MPI_Status status;
   MPI_Init(&argc, &argv);
   MPI_Comm_rank(MPI_COMM_WORLD, &rank);
   MPI_Comm_size(MPI_COMM_WORLD,&size); 
   a = 0.0;
   b = 0.0;
   t=MPI_Wtime();          
   if(rank == 0)
   {
      sprintf(WR,"Hello from %d",rank); 
      MPI_Send(WR,leng,MPI_CHAR, 1, 5, MPI_COMM_WORLD);
      MPI_Recv(WR,leng,MPI_CHAR, 1, 5, MPI_COMM_WORLD, &status);
   }
   if(rank == 1)
   {
      sprintf(WR,"Hello from %d",rank); 
      MPI_Recv(WR,leng,MPI_CHAR, 0, 5, MPI_COMM_WORLD, &status);
      MPI_Send(WR,leng,MPI_CHAR, 0, 5, MPI_COMM_WORLD);
   }
   printf("process %d\n", rank);
   MPI_Finalize();
}*/
#include "mpi.h"
#include <stdio.h>
int main(int argc, char **argv)
{
   int rank;
   float a, b;
   MPI_Status status;
   MPI_Init(&argc, &argv);
   MPI_Comm_rank(MPI_COMM_WORLD, &rank);
   a = 0.0;
   b = 0.0;
   if(rank == 0)
   {
      b = 1.0;
      MPI_Send(&b, 1, MPI_FLOAT, 1, 6, MPI_COMM_WORLD);
      MPI_Recv(&a, 1, MPI_FLOAT, 1, 6, MPI_COMM_WORLD, &status);
   }
   if(rank == 1)
   {
      a = 2.0;
      MPI_Recv(&b, 1, MPI_FLOAT, 0, 6, MPI_COMM_WORLD, &status);
      MPI_Send(&a, 1, MPI_FLOAT, 0, 6, MPI_COMM_WORLD);
   }
   printf("process %d a = %f, b = %f\n", rank, a, b);
   MPI_Finalize();
}

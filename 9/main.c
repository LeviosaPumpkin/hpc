#include <mpi.h> 
#include <stdio.h> 
#include <time.h>
#define leng 5 
#define head 0

int main( int argc, char **argv ) 
{ 
	double     t,t2;     
	int     i,rank,size;     
	int     WR[leng], id[leng]; 
	int massons=10;   
 	int yes=0;
	int no=0;
	MPI_Status     status;
	for(i=0; i<leng;++i) 
	{
		WR[i]=rand()%2;
		if(WR[i]==1) ++yes;
		else ++no;
	}
	MPI_Init( &argc, &argv ); 
	MPI_Comm_rank( MPI_COMM_WORLD, &rank ); 
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	t=MPI_Wtime(); //фиксация времени «начала посылки»,  
	if(rank != head)
   	{ 
      		MPI_Send(&WR[rank],1,MPI_INT, head, 0, MPI_COMM_WORLD);
      		//MPI_Recv(&WR[rank],1,MPI_INT, head, rank, MPI_COMM_WORLD, &status);
		printf("From masson %d %d\n",rank,WR[rank]); 
   	}
   	if(rank == head)
   	{
		for ( i=1; i < size; i++ )
		{
			MPI_Recv(&WR[rank],1,MPI_INT, MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &status);
		}
		printf("Yes: %d\nNo: %d\n",yes,no);
   	}
	t2=MPI_Wtime();
	MPI_Finalize();
	printf("Time %f\n", t2-t);
	return 0;     
}
/*Time 0.000347
Time 0.001250
Time 0.000456
Time 0.000044
Time 0.000050
*/



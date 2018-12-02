#include <mpi.h>
#include <stdio.h> 

int main(int argc, char* argv[])

{
	int proc_rank, proc_count;
	int mas1[10],mas2[10];
	int i;
	int count;
	double t,t2;
	MPI_Status     status, gstatus;
	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &proc_count);
	MPI_Comm_rank(MPI_COMM_WORLD, &proc_rank);
	if (proc_rank==0) 
		for (i=0; i<10; i++)
			mas1[i]=i+1;
	t=MPI_Wtime();
	MPI_Alltoall(mas1,10,MPI_INT, mas2,10,MPI_INT, MPI_COMM_WORLD);
	printf("%d sent time %f\n",proc_rank,MPI_Wtime()-t);
	MPI_Finalize();
	exit(0); 
	return 0;

}
/* time 0.005882

 time 0.007963

 time 0.009169
*/



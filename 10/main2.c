#include <mpi.h>
#include <stdio.h> 

int main(int argc, char* argv[])

{
	int proc_rank, proc_count;
	int mas1[10],mas2[10];
	int i;
	double     t,t2;
	MPI_Status     status;

	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &proc_count);
	MPI_Comm_rank(MPI_COMM_WORLD, &proc_rank);
	

	if (proc_rank==0) 
		for (i=0; i<10; i++)
			mas1[i]=i+1;
	t=MPI_Wtime();
	//MPI_Bcast (mas, 10, MPI_INT, 0, MPI_COMM_WORLD);
	/*for (i=0; i<proc_count;++i)
	{
		if (i!=proc_rank) 
		{
			MPI_Send(mas,10,MPI_INT, i, 0, MPI_COMM_WORLD);
			printf("%d sent to %d\n",proc_rank, i);
		}
		else MPI_Recv(mas,10,MPI_INT, MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &status);
	}*/
	MPI_Alltoall(mas1,10,MPI_INT, mas2,10,MPI_INT, MPI_COMM_WORLD);
	printf("%d sent \n",proc_rank);

	MPI_Finalize();
	printf("\n time %f\n", MPI_Wtime()-t);
	return 0;

}
/* time 0.005882

 time 0.007963

 time 0.009169
*/

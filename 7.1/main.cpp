#include <omp.h>
#include <stdio.h>
#include <math.h>

int main(int argc, char **argv)
{
	int N=10;
	double x[N],y[N]; 
	x[0] = 2; 
	y[0] = 1;
	int e=2;
	int o=1;
	//#pragma omp for nowait 
	
		for (int i=1; i<N; ++i) 
		{ 
			x[i] = pow(x[0], i+1); //т.к. все последующие значения массива являются степенью 0ого 
			if(i%2==0) 
			{
				y[i]=pow(x[0],e)*y[0];
				++e;
			}
			else 
			{
				y[i]=pow(x[0],o)/y[0];
				++o;
			}
		} 
	
	//y[N]=x[N-2];
	printf("x\t");
	printf("y\n");
	for (int i=0; i<N; ++i)
	{
		printf("%f\t",x[i]);
		printf("%f\n",y[i]);
	}
	return 0;
}

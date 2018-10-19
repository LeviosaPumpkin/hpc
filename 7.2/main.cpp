#include <omp.h>
#include <iostream>
#include <cmath>

int main(int argc, char **argv)
{
	int n=4;
	int a = 2;
	int b=3;
	int j=0;
	int i=0;
	omp_set_num_threads(n);
	#pragma omp parallel for schedule(static) reduction(+:j)
	for(i=1; i<7; i+=2) 
	{
		#pragma omp critical
		{
			std::cout<<"C"<<i<<"*"<<a<<"^"<<n-j<<"*x^"<<n-j<<"*"<<b<<"^"<<j<<"*y^"<<j<<
				"+C"<<i+1<<"*"<<b<<"^"<<n-j<<"*y^"<<n-j<<"*"<<a<<"^"<<j<<"*x^"<<j<<"+\n";
		}
		++j;
	}
	std::cout<<"+K\n";
	return 0;
}


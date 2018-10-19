#include <omp.h>
#include <iostream>
#include <cmath>

int main(int argc, char **argv)
{
	int n=4;
	int a = 2;
	int b=3;
	
	for(int i=1,j=0; i<7; i+=2,++j)
	{
		std::cout<<"C"<<i<<"*"<<a<<"^"<<n-j<<"*x^"<<n-j<<"*"<<b<<"^"<<j<<"*y^"<<j<<
			"+C"<<i+1<<"*"<<b<<"^"<<n-j<<"*y^"<<n-j<<"*"<<a<<"^"<<j<<"*x^"<<j<<"+\n";
	}
	std::cout<<"+K\n";
	return 0;
}


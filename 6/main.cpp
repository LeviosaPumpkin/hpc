/*Дана последовательность натуральных чисел {a0...an–1}. 
Создать OpenMP-приложение для поиска суммы ∑ai, 
где ai – простые числа. */
#include <omp.h>
#include <iostream>
#include <vector>

void print(const std::vector<int> &v)
{
	for(int i=0;i<v.size();++i) std::cout << v[i] << " ";
	std::cout<<std::endl;
}
bool is_prime(int x)
{
	if(1==x || 0==x) return false;
	int j;
    	for (j = 2; j <= (x / j); j++)
	{
		if (!(x % j)) break;
	}
	if (j > (x / j)) return true;
	return false;
}
int main(int argc, char **argv)
{
	
	const int n=100;
	std::vector<int> a(n);
	a[0]=0;
	int sum=0;
	for (int i=1; i<n; ++i) a[i]=++a[i-1];
	std::cout<<n<<std::endl;
	int max_threads = omp_get_max_threads();
	std::cout<<"Max threads: "<< max_threads <<std::endl;
	if (max_threads<4) omp_set_num_threads(max_threads);
	else omp_set_num_threads(4);      
	#pragma omp parallel for schedule(static) private(i) shared(a) reduction(+:sum) 
	for(int i=0; i<n; ++i)
	{
		#pragma omp critical
			std::cout<<"a[i]= "<<a[i]<<"\n";
		if(is_prime(a[i])) sum+=a[i];
	}
	std::cout<<std::endl<<sum<<std::endl;
	return 0;
}

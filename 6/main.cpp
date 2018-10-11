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

int main(int argc, char **argv)
{
	
	const int n=100;
	std::vector<int> a(n);
	int sum=0;
	for (int i=0; i<n; ++i) a[i]=i;
	std::cout<<n<<std::endl;
	int j=2;
	std::cout<<"Max threads: "<< omp_get_max_threads()<<std::endl;
	#pragma omp parallel for
	for(int i=0; i<n; ++i)
	{
		if(1==a[i] || 0==a[i]) continue;
		for(;j<=(a[i]/j);++j)
		{
			if(!(a[i]%j)) break;
		}
		if(j>(a[i]/j)) sum+=a[i];
	}
	std::cout<<sum<<std::endl;
	return 0;
}

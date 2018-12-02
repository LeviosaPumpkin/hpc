#include <iostream>
#include <vector>
#include <exception>
#include <cmath>
#include <chrono>
#include "Vector.h"

bool test()
{
	std::vector<Vector> v(80000000);
	for (int i = 0; i < v.size(); ++i)
	{
		v[i].x = i + 1;
		v[i].y = i + 1;
		v[i].z = i + 1;
	}
	std::vector<double> cos = countCos(v);
	for (int i = 0; i < cos.size(); ++i)
	{
		if (cos[i] != (i + 1) / sqrt((3 * pow(i + 1, 2)))) return false;
	}
	return true;
}

void main()
{
	auto start = std::chrono::steady_clock::now();
	if (test()) std::cout << "OK\n";
	else std::cout << "not OK\n";
	auto end = std::chrono::steady_clock::now();
	auto diff = end - start;
	std::cout << std::chrono::duration <double, std::milli>(diff).count() << " ms" << "\n";
	std::cout << "Enter number of vectors to count: ";
	int num = 0;
	try
	{
		std::cin >> num;
	}
	catch (std::exception & e)
	{
		std::cerr << "Not a number\n";
	}
	/*std::vector<Vector> v(num);
	std::vector<double> cos = countCos(v);
	for (int i = 0; i < num; ++i)
	{
		std::cout << v[i].x << " " << v[i].y << " " << v[i].z << " " << cos[i] << "\n";
	}*/
}
//just code 106965
//vectorized 104877
//data alignment 103190
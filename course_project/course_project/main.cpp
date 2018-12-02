#include <iostream>
#include <vector>
#include <exception>
#include "Vector.h"

void main(void)
{
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
	std::vector<Vector> v(num);
	std::vector<double> cos = countCos(v);
	for (int i = 0; i < num; ++i)
	{
		std::cout << v[i].x << " " << v[i].y << " " << v[i].z << " " << cos[i] << "\n";
	}
}
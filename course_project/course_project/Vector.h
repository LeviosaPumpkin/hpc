#ifndef VECTOR_H
#define VECTOR_H

#include <ctime>
#include <cmath>

struct Vector
{
	int x, y, z;
	Vector()
	{
		/*x = std::rand();
		y = std::rand();
		z = std::rand();*/
	}
};
std::vector<double> countCos(std::vector<Vector> & v)
{
	std::vector<double> cos(v.size());
	for (int i = 0; i < v.size(); ++i)
	{
		double length = sqrt(pow(v[i].x, 2) + pow(v[i].y, 2) + pow(v[i].z, 2));
		cos[i] = v[i].x / length;
		//std::cout << v[i].x << " " << v[i].y << " " << v[i].z << " " << cos[i] << "\n";
	}
	return cos;
}

#endif
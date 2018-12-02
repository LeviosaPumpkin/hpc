#ifndef VECTOR_H
#define VECTOR_H

#include <ctime>
#include <cmath>

_declspec(align(2)) struct Vector
{
	int x, y, z;
};
std::vector<double> countCos(std::vector<Vector> & v)
{
	std::vector<double> cos(v.size());
#pragma clang loop vectorize(enable) 
	for (int i = 0; i < v.size(); ++i)
	{
		double length = sqrt(pow(v[i].x, 2) + pow(v[i].y, 2) + pow(v[i].z, 2));
		cos[i] = v[i].x / length;
	}
	return cos;
}

#endif
#include "Vector.h"

std::vector<double> countCos(std::vector<Vector> & v, int n)
{
	std::vector<double> cos(n);
#pragma omp parallel for
	for (int i = 0; i < n; ++i)
	{
		double length = sqrt(pow(v[i].x, 2) + pow(v[i].y, 2) + pow(v[i].z, 2));
		cos[i] = v[i].x / length;
	}
	return cos;
}

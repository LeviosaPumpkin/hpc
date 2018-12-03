#include <vector>
#include <cmath>
#include <omp.h>
struct Vector
{
	int x, y, z;
}__attribute__((__aligned__(2)));
std::vector<double> countCos(std::vector<Vector> & v, int n);


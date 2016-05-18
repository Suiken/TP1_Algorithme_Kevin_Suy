/** 
	Kevin SUY 
	Classe Grand_Entier permettant de calculer la multiplication de grands entiers de façon plus optimisée en implémentant l'algorithme de Karatsuba
**/
#include <algorithm>
#include "Grand_Entier.h"

using namespace std;
int get_size(long num);
long multiply(long x, long y);
Grand_Entier::Grand_Entier()
{
	this->value = 0;
}

Grand_Entier::Grand_Entier(long value){
	this->value = value;
}

Grand_Entier& Grand_Entier::operator*(Grand_Entier &other_grand_entier)
{
	return Grand_Entier(multiply(this->value, other_grand_entier.get_value()));
}

long Grand_Entier::get_value(){
	return this->value;
}

long multiply(long x, long y)
{
	int size1 = get_size(x);
	int size2 = get_size(y);

	int N = std::max(size1, size2);

	if (N < 10)
		return x * y;

	N = (N / 2) + (N % 2);

	long m = (long)std::pow(10, N);

	long b = x / m;
	long a = x - (b * m);
	long d = y / m;
	long c = y - (d * N);

	long z0 = multiply(a, c);
	long z1 = multiply(a + b, c + d);
	long z2 = multiply(b, d);

	return z0 + ((z1 - z0 - z2) * m) + (z2 * std::pow(10, 2 * N));
}

int get_size(long num)
{
	int ctr = 0;

	while (num != 0)
	{
		ctr++;
		num /= 10;
	}

	return ctr;
}

Grand_Entier::~Grand_Entier()
{
}

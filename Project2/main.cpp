#include "Vector.h"
#include<cstdio>

int main() {

	Vector v(3);
	v[0] = 3;
	v[1] = 4;
	v[2] = 1.1;

	Vector a(3);
	a[0] = -3.9;
	a[1] = 7;
	a[2] = -9;

	a.print();

	printf("\n");
	v.print();
	printf("\n");

	(a + v).print();
	printf("\n");

	a += v;
	a.print();
	printf("\n");

	a *= 5;
	a.print();
	printf("\n");


	printf("%lf\n", a.dot(v));
	printf("%lf\n", a.getNorm());


	return 0;
}




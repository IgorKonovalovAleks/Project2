#include "Matrix.h"
#include<cstdio>

int main() {
	/*
	MyVector v(5);
	v[1] = 7.5;
	v[4] = 1;

	MyVector a = v;
	a[2] = 4;

	v.print();
	a.print();

	printf("%lf\n\n", a.popBack());
	a.print();
	
	MyVector b(1);
	b[0] = 4;
	b.print();
	b.pushBack(3);
	b.print();
	b.pushBack(1);
	b.print();
	*/
	Matrix a(3, 2);
	Matrix m(2, 3);
	m[1][0] = 3;
	a[1][1] = 6;
	
	Matrix r(a * m);
	r.print();

	return 0;
}




#include "Matrix.h"
#include "myVector.h"
#include<cstdio>

int main() {
	
	
	Vector o(4);
	o[0] = 1;
	o[1] = 2;
	o[3] = 5;
	Vector f(4);
	f = 3 * o;
	f = o * 2;
	printf("%lf\n", o.dot(f));
	f.print();
	








	printf("\nDYNAMIC VECTOR\n");
	MyVector v(5);
	v[1] = 7.5;
	v[4] = 1;

	MyVector c = v;
	c[2] = 4;

	v.print();
	c.print();


	printf("%lf\n\n", c.popBack());
	c.print();
	
	MyVector b(1);
	b[0] = 4;
	b.print();
	b.pushBack(3);
	b.print();
	b.pushBack(1);
	b.print();
	b.insert(1, 3);
	b.print();
	b.erase(2);
	b.print();

	MyVector w(2);
	w.print();
	w.resize(5);

	w.print();

	printf("\nMATRIX\n");
	Matrix a(2, 3);
	Matrix m(3, 2);
	m[1][0] = 2;
	m[0][1] = 1;
	a[1][1] = 6;
	a[0][0] = 3;
	a[1][0] = 2;
	m.print();
	printf("\n");
	a.print();
	printf("\n");
	
	Matrix r(m * a);
	r.print();

	return 0;
}




#include "Matrix.h"
#include "Vector.h"
#include "GaussSolver.h"
#include <iostream>

int main() {
	

	//example
	/*
	Matrix m(5, 7);
	m[0][0] = 2; m[0][1] = 3; m[0][2] = 5; m[0][3] = 3; m[0][4] = 0; m[0][5] = 0; m[0][6] = 0;
	m[1][0] = 0; m[1][1] = -4; m[1][2] = 0; m[1][3] = 8; m[1][4] = 0; m[1][5] = 1; m[1][6] = -7;
	m[2][0] = 0; m[2][1] = 0; m[2][2] = 0; m[2][3] = -8; m[2][4] = 0; m[2][5] = 1; m[2][6] = 4;
	m[3][0] = 0; m[3][1] = 0; m[3][2] = 0; m[3][3] = 0; m[3][4] = 0; m[3][5] = 1; m[3][6] = 0;
	m[4][0] = 0; m[4][1] = 0; m[4][2] = 0; m[4][3] = 0; m[4][4] = 0; m[4][5] = 0; m[4][6] = 0;
	m.print();
	
	Vector b(5);
	b[0] = -1;
	b[1] = 0;
	b[2] = 3;
	b[3] = 5;
	b[4] = 0;
	b.print();
	printf("\n");
	*/

	Matrix m(3, 4);
	m[0][0] = 2; m[0][1] = 3; m[0][2] = 2; m[0][3] = 1;
	m[1][0] = 3; m[1][1] = -2; m[1][2] = 2; m[1][3] = 2;
	m[2][0] = 1; m[2][1] = 2; m[2][2] = 1; m[2][3] = 0;
	
	m.print();

	Vector b(3);
	b[0] = -1;
	b[1] = 3;
	b[2] = 3;
	b.print();
	printf("\n");

	GaussSolver solver;
	std::vector<Vector> res = solver.solve(m, b);


	
	std::cout << "\n";
	for (Vector v : res) {
		v.print();
		std::cout << "\n";
	}
	

	/*
	Vector o(4);
	o[0] = 1;
	o[1] = 2;
	o[3] = 5;
	Vector f(4);
	f = 3 * o;
	f = o * 2;
	printf("%lf\n", o.dot(f));
	f.print();
	

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
	*/
	return 0;
}




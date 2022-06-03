#pragma once
#include "Matrix.h"
#include "Vector.h"
#include <cstdio>
#include <Vector>
#include <cmath>

class GaussSolver {

public:

	GaussSolver();

	std::vector<Vector> solve(const Matrix& A, const Vector& b);
	void find_max(const Matrix& A, int& i, int& j, Vector& allo_i, Vector& allo_j);
	void exclude_column(Matrix& A, Vector& b, int i, int j);


};



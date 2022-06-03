#include "GaussSolver.h"




GaussSolver::GaussSolver() {}


void GaussSolver::find_max(const Matrix& A, int& i, int& j, Vector& allo_i, Vector& allo_j) {
	
	for (int a = 0; a < allo_i.getLength(); a++) {
		if (allo_i[a] == 1) {
			i = a;
			break;
		}
	}
	for (int b = 0; b < allo_j.getLength(); b++) {
		if (allo_j[b] == 1) {
			j = b;
			break;
		}
	}

	for (int a = 0; a < allo_i.getLength(); a++) {
		if (allo_i[a] == 0)
			continue;
		for (int b = 0; b < allo_j.getLength(); b++) {
			if (allo_j[b] == 0)
				continue;
			if (std::abs(A[a][b]) > std::abs(A[i][j])) {
				i = a;
				j = b;
			}
		}
	}
}


void GaussSolver::exclude_column(Matrix& A, Vector& b, int i, int j) {

	double val = A[i][j];
	A[i] *= 1 / val;
	b[i] /= val;

	for (int a = 0; a < b.getLength(); a++) {
		if (a != i) {
			b[a] -= b[i] * A[a][j];
			A[a] -= A[i] * A[a][j];
		}
		
	}
	

}


std::vector<Vector> GaussSolver::solve(const Matrix& Mat, const Vector& Sc) {

	Matrix A(Mat);
	Vector b(Sc);

	Vector allowed_i(A.getRw());
	Vector allowed_j(A.getCl());

	Vector is_base(A.getCl());

	for (int i = 0; i < A.getCl(); i++) {
		is_base[i] = 0;
	}
	for (int i = 0; i < A.getRw(); i++) {
		allowed_i[i] = 1;
	}
	for (int i = 0; i < A.getCl(); i++) {
		allowed_j[i] = 1;
	}

	int i, j;
	int rank = 0;
	for (int a = 0; a < A.getRw(); a++) {
		find_max(A, i, j, allowed_i, allowed_j);

		allowed_i[i] = 0;                              //prohibit used rows/columns
		allowed_j[j] = 0;
		
		rank++;

		if (A[i][j] != 0) {
			exclude_column(A, b, i, j);
			is_base[j] = 1;
		}
		else
			break;
	}


	
	for (i = 0; i < A.getRw(); i++) {
		allowed_i[i] = 1;
	}
	int null_rows = 0;
	//search for null rows
	for (i = 0; i < A.getRw(); i++) {
		bool f = true;
		for (j = 0; j < A.getCl(); j++) {
			if (A[i][j] != 0) {
				f = false;
				break;
			}
		}
		if (f && b[i] != 0) {              //no solutions
			return std::vector<Vector>();
		} 
		else if (f) {
			null_rows++;
			allowed_i[i] = 0;
		}
	}
	rank -= null_rows;

	//printf("\nrank %d\n", rank);
	std::vector<Vector> result;
	Vector col(A.getRw());
	result.push_back(b);
	if (rank < A.getCl()) {
		for (i = 0; i < A.getCl(); i++) {
			if (is_base[i] == 0) {
				for (int j = 0; j < col.getLength(); j++)
					col[j] = A[j][i]  == 0 ? 0 : -1 * A[j][i];
				result.push_back(col);
			}
		}
	}
	/*
	printf("\nMatrix:\n");
	A.print();
	b.print();
	
	printf("\n");
	*/
	return result;

}







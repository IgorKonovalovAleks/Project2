#include "GaussSolver.h"


const double ZERO = 0.00000000000001;

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
		is_base[i] = -1;
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

		if (abs(A[i][j]) > ZERO) {
			//printf("%lf\n", A[i][j]);
			exclude_column(A, b, i, j);
			//A.print();
			//b.print();
			//printf("\n\n");
			is_base[j] = i;
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
			if (abs(A[i][j]) > ZERO) {
				f = false;
				break;
			}
		}
		if (f && abs(b[i]) > ZERO) {              //no solutions
			return std::vector<Vector>();
		} 
		else if (f) {
			null_rows++;
			allowed_i[i] = 0;
		}
	}
	rank -= null_rows;

	//printf("\nrank %d\n", rank);
	Vector col(A.getCl());
	std::vector<Vector> res;

	//calculate shift
	for (int a = 0; a < col.getLength(); a++) {
		if (is_base[a] == -1)
			col[a] = 0;
		else
			col[a] = b[is_base[a]];
	}

	res.push_back(col);


	//repeat for every free x
	for (int z = 0; z < A.getCl(); z++) {
		if (is_base[z] == -1) {
			for (int a = 0; a < col.getLength(); a++) {

				if (a == z)
					col[a] = 1;

				else if (is_base[a] == -1)
					col[a] = 0;

				else
					col[a] = A[is_base[a]][z] == 0 ? 0 : -A[is_base[a]][z];


			}

			res.push_back(col);

		}

	}
	
	//printf("\nMatrix:\n");
	//A.print();
	//b.print();
	
	printf("\n");
	
	return res;

}







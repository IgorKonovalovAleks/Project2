#include "Matrix.h"


Matrix::Matrix() {
	d = new Vector[0];
	rw = 0;
	cl = 0;
}


Matrix::Matrix(int r, int c) {
	
	rw = r;
	cl = c;
	d = new Vector[rw];
	for (int i = 0; i < rw; i++) {
		d[i] = Vector(cl);
	}


}

Matrix::Matrix(const Matrix& m) {
	rw = m.rw;
	cl = m.cl;
	d = new Vector[rw];
	for (int i = 0; i < rw; i++) {
		d[i] = Vector(m[i]);
	}
}

Matrix::~Matrix() {
	delete[] d;
}

Vector& Matrix::operator[](int i) {
	return d[i];
}

Vector Matrix::operator[](int i) const {
	return d[i];
}


Matrix Matrix::operator+(const Matrix& m) const {
	if (cl != m.cl || rw != m.rw) {
		printf("er");
		return Matrix();
	}
	Matrix r(rw, cl);
	for (int i = 0; i < rw; i++) {
		r[i] = d[i] + m[i];
	}
	return r;
}

Matrix Matrix::operator-(const Matrix& m) const {
	if (cl != m.cl || rw != m.rw) {
		printf("er");
		return Matrix();
	}
	Matrix r(rw, cl);
	for (int i = 0; i < rw; i++) {
		r[i] = d[i] - m[i];
	}
	return r;
}

void Matrix::resize(int newRw, int newCl) {
	delete[] d;
	rw = newRw;
	cl = newCl;
	d = new Vector[rw];
	for (int i = 0; i < rw; i++) {
		d[i]= Vector(cl);
	}

}

Matrix& Matrix::operator=(const Matrix& m) {
	if (cl != m.cl || rw != m.rw) {
		resize(m.rw, m.cl);
	}
	for (int i = 0; i < rw; i++) {
		d[i] = m[i];
	}
	return *this;
}


Matrix& Matrix::operator+=(const Matrix& m) {
	if (cl != m.cl || rw != m.rw) {
		printf("er");
		return *this;
	}
	for (int i = 0; i < rw; i++) {
		d[i] += m[i];
	}
	return *this;
}


Matrix& Matrix::operator-=(const Matrix& m) {
	if (cl != m.cl || rw != m.rw) {
		printf("er");
		return *this;
	}
	for (int i = 0; i < rw; i++) {
		d[i] -= m[i];
	}
	return *this;
}

Matrix Matrix::operator*(double c) const {

	Matrix r(rw, cl);
	for (int i = 0; i < rw; i++) {
		r[i] = d[i] * c;
	}

	return r;

}



Matrix& Matrix::operator*=(double c) {

	for (int i = 0; i < rw; i++) {
		d[i] *= c;
	}
	return *this;
}



Matrix Matrix::operator*(const Matrix& m) const {

	if (cl != m.rw) {
		printf("er");
		return Matrix();
	}
	else {
		Matrix r(rw, m.cl);
		for (int i = 0; i < rw; i++) {
			for (int j = 0; j < m.cl; j++) {

				for (int k = 0; k < cl; k++) {
					r[i][j] += d[i][k] * m.d[k][j];
				}


			}
		}
		return r;
	}


}





void Matrix::print() const {

	for (int i = 0; i < rw; i++) {
		d[i].print();
		printf("\n");
	}


}


Matrix operator*(double a, Matrix c) {

	Matrix r(c.rw, c.cl);
	for (int i = 0; i < c.rw; i++) {
		r[i] = c[i] * a;
	}

	return r;

}
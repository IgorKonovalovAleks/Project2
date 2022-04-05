#include "Vector.h"
#include <cstdlib>
#include <cstdio>


Vector::Vector() {
	d = new double[0];

}


Vector::Vector(int len) {
	n = len;
	d = new double[len];
	for (int i = 0; i < n; i++) {
		d[i] = 0;
	}

}

Vector::Vector(const Vector& v) {
	n = v.n;
	d = new double[n];
	for (int i = 0; i < n; i++) {
		d[i] = v[i];
	}


}

Vector::~Vector() {
	delete[] d;
}




int Vector::getLength() const {
	return n;
}

Vector Vector::operator+(const Vector &v) const {
	if (this->getLength() != v.getLength()) {
		printf("er");
		return Vector();
	}
	Vector r(n);
	for (int i = 0; i < n; i++) {
		r[i] = d[i] + v[i];
	}
	return r;
}

Vector Vector::operator-(const Vector& v) const {
	if (this->getLength() != v.getLength()) {
		printf("er");
		return Vector();
	}
	Vector r(n);
	for (int i = 0; i < n; i++) {
		r[i] = d[i] - v[i];
	}
	return r;
}


Vector Vector::operator*(double c) const {

	Vector r(n);
	for (int i = 0; i < n; i++) {
		r[i] = d[i] * c;
	}

	return r;

}

Vector& Vector::operator*=(double c) {
	
	for (int i = 0; i < n; i++) {
		d[i] *= c;
	}
	return *this;
}

Vector& Vector::operator+=(const Vector& v) {
	if (this->getLength() != v.getLength()) {
		printf("er");
		return *this;
	}
	for (int i = 0; i < n; i++) {
		d[i] += v[i];
	}
	return *this;
}


Vector& Vector::operator-=(const Vector& v) {
	if (this->getLength() != v.getLength()) {
		printf("er");
		return *this;
	}
	for (int i = 0; i < n; i++) {
		d[i] -= v[i];
	}
	return *this;
}




void Vector::resize(int nSize) {
	delete[] d;
	d = new double[nSize];
	n = nSize;
	for (int i = 0; i < n; i++) {
		d[i] = 0;
	}

}

Vector& Vector::operator=(const Vector& v) {
	if (this->getLength() != v.getLength()) {
		resize(v.getLength());
	}
	for (int i = 0; i < n; i++) {
		d[i] = v[i];
	}
	return *this;
}


double& Vector::operator[](int i) {
	return d[i];
}

double Vector::operator[](int i) const {
	return d[i];
}



double Vector::dot(const Vector& v) const {
	if (this->getLength() != v.getLength()) {
		printf("er");
		return -1;
	}
	double r = 0;
	for (int i = 0; i < n; i++) {
		r += d[i] * v[i];
	}
	return r;
}



void Vector::print() const {

	for (int i = 0; i < n; i++) {
		printf("%lf\n", d[i]);
	}


}

void Vector::setVal(int i, double val) {
	if (i < n) {
		d[i] = val;
	}
	else
		printf("er");
}


double Vector::getNorm() const {
	return sqrt(this->dot(*this));
}


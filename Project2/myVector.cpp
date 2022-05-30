#include "myVector.h"



void MyVector::insert(int idx, double val) {
	resize(n + 1);
	for (int i = n; i > idx; i--) {
		d[i] = d[i - 1];
	}
	d[idx] = val;
}

void MyVector::erase(int idx) {
	for (int i = idx; i < n - 1; i++) {
		d[i] = d[i + 1];
	}
	resize(n - 1);
}

MyVector::MyVector() {
	d = new double[0];

}


MyVector::MyVector(int len) {
	n = len;
	capacity = len * CAPACITY_FACTOR;
	d = new double[capacity];
	for (int i = 0; i < n; i++) {
		d[i] = 0;
	}

}

MyVector::MyVector(const MyVector& v) {
	n = v.n;
	d = new double[n * CAPACITY_FACTOR];
	capacity = n * CAPACITY_FACTOR;
	for (int i = 0; i < n; i++) {
		d[i] = v[i];
	}


}

MyVector::~MyVector() {
	delete[] d;
}

double& MyVector::operator[](int i) {
	return d[i];
}

double MyVector::operator[](int i) const {
	return d[i];
}

MyVector& MyVector::operator=(const MyVector& v) {
	if (n != v.n) {
		resize(v.getLength());
	}
	for (int i = 0; i < n; i++) {
		d[i] = v[i];
	}
	return *this;
}


int MyVector::getLength() const {
	return n;
}


void MyVector::resize(int nSize) {
	if (nSize <= capacity) {
		n = nSize;
	}
	else {
		double* v = new double[nSize * CAPACITY_FACTOR];
		
		for (int i = 0; i < n; i++) {
			v[i] = d[i];
		}
		for (int i = n; i < nSize; i++) {
			v[i] = 0;
		}
		n = nSize;
		delete[] d;
		d = v;
		
		capacity = nSize * CAPACITY_FACTOR;

	}
}


void MyVector::pushBack(double a) {

	if (n < capacity) {
		d[n] = a;
		n += 1;
	}
	else {
		resize(n + 1);
		d[n - 1] = a;
	}


}

double MyVector::popBack() {
	if (n == 0) {
		printf("er");
		return -1;
	}
	else {
		n--;
		return d[n];
	}

}


void MyVector::print() const {
	for (int i = 0; i < n; i++) {
		printf("%lf ", d[i]);
	}
	printf("\n");


}


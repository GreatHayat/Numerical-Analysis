// trapezoidal.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;

void getValue(double *x, double *function, int size) {
	cout << "Enter Value of X: " << endl;
	for (int i = 0; i < size; i++) {
		cin >> x[i];
	}
	cout << "Enter Value of F(x): " << endl;
	for (int i = 0; i < size; i++) {
		cin >> function[i];
	}
}
double interval(double *x, int size) {
	double result = (x[size - 1] - x[0]) / (size - 1);
	return result;
}
double extreme(double *function , int size) {
	double result = function[0] + function[size - 1];
	return result;
}
double remaining(double *function, int size) {
	double result = 0;
	for (int i = 1; i < size; i++) {
		result = result + function[i];
	}
	return result;
}
double result(double *function , double *x , int size) {
	double result = (interval(x, size) / 2)*(extreme(function, size) + 2 * remaining(function, size - 1));
	return result;
}
int main()
{
	int size;
	cout << "Enter Size of Array: " ;
	cin >> size;
	double* function = new double[size];
	double* x = new double[size];
	getValue(x, function, size);
	cout << "Result of Trapezoidal : " << result(function, x, size) << endl;
	system("pause");
	delete x;
	delete function;
    return 0;
}


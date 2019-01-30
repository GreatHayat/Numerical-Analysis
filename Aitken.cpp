// NA_Aitkens.cpp : Defines the entry point for the console application.
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

double findValue(double xp, double xi, double xj, double func1, double func2) {
	double result;
	result = ((xp - xi) * func2) - ((xp - xj) * func1);
	result = result / (xj - xi);
	return result;
}

double result(double *function, double *x, double xp, int size) {
	double result = 0;
	double *array = new double[size];
	for (int i = 0; i < size - 1; i++) {
		for (int j = i + 1; j < size ; j++) {
			array[j] = findValue(xp, x[i], x[j], function[j - 1], function[j]);
			result = array[j];
		}
	}
	delete array;
	return result;
}
int main()
{
	double xp;
	int size;
	cout << "Enter Size of Array: " << endl;
	cin >> size;
	double* function = new double[size];
	double* x = new double[size];
	getValue(x, function, size);
	cout << "Enter Value of Xp: " << endl;
	cin >> xp;
	cout << "Result of Aitken's : " << result(function, x, xp, size) << endl;
	system("pause");
	delete function;
	delete x;
	return 0;
}


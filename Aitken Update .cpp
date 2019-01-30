#include "stdafx.h"
#include<iostream>
using namespace std;

void getValue(double *x, double **function, int size) {
	cout << "Enter Value of X: " << endl;
	for (int i = 0; i < size; i++) {
		cin >> x[i];
	}
	cout << "Enter Value of F(x): " << endl;
	for (int i = 0; i < size; i++) {
		cin >> function[0][i];
	}
}

double findValue(double xp, double xi, double xj, double func1, double func2) {
	double result;
	//cout << "function 1 : " << func1 << " functioj 2 : " << func2 << " xp : " <<xp << " xi : " << xi  << " xj : " << xj<< endl;
	result = ((xp - xi) * func2) - ((xp - xj) * func1); 
	//cout << "Result of func1 and func2 : " << result << endl;
	if (result < 0) {
		result = result * (-1);
	}
	result = result / (xj - xi);
	return result;
}

double result(double **function, double *x, double xp, int size) {
	double result = 0;
	for (int i = 0; i < size - 1; i++) {
		for (int j = i + 1; j < size ; j++) {
			result= findValue(xp, x[i], x[j], function[i][i], function[i][j]);
			function[i + 1][j] = result;
			//cout << "\nResult : " << result << endl;
		}
	}
	return result;
}
int main()
{
	double xp;
	int size;
	cout << "Enter Size of Array: " << endl;
	cin >> size;
	double **function;
	function = new double*[size];
	for (int i = 0; i < size; i++) {
		function[i] = new double[size];
	}
	double* x = new double[size];
	getValue(x, function, size);
	cout << "Enter Value of Xp: " << endl;
	cin >> xp;
	cout << "Result of Atiken : " << result(function, x, xp, size) << endl;
	system("pause");
	delete function;
	delete x;
	return 0;
}

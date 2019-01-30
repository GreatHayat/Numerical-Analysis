// NA_Assignment.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;
void getValue(double *&x, double *&function, int size) {
	cout << "Entr Value of X: " << endl;
	for (int i = 0; i < size; i++) {
		cin >> x[i];
	}
	cout << "Enter Value of Function: " << endl;
	for (int i = 0; i < size; i++) {
		cin >> function[i];
	}
}
double resultOfLangrange(double *function, double *x, double xp, int size) {
	double result = 0;
	double *array;
	array = new double[size];
	for (int i = 0; i < size; i++) {
		array[i] = function[i];
		for (int j = 0; j < size; j++) {
			if (i != j) {
				array[i] = (array[i] * (xp - x[j])) / (x[i] - x[j]);
			}	
		} 
		result = result + array[i];
	}
	return result;
}
int main()
{
	double *x, *function , result, xp;
	int size;
	cout << "Enter Value of Size: " << endl;
	cin >> size;
	x = new double[size];
	function = new double[size];
	getValue(x, function, size);
	cout << "Enter Value of Xp: " << endl;
	cin >> xp;
	result = resultOfLangrange(function, x, xp, size);
	cout << "Result of Lagrange : " << result << endl;
	system("pause");
    return 0;
}


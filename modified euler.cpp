
// modified_euler.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
double function1(double y0, double x0) {
	double result = x0 + y0;
	return result;
}
double function2(double y0, double x0 , double interval) {
	double x = x0 + interval / 2;
	double y = y0 + (interval / 2)*function1(y0, x0);
	double result = function1(y, x);
	return result;
}

double euler_result(double y0, double x0, int size, double interval) {
	double result = 0;
	for (int i = 1; i < size; i++) {
		result = y0 + interval*function2(y0 , x0 , interval);
		x0 = x0 + interval;
		y0 = result;
	}
	return result;
}
int main()
{
	double x0, y0, interval;
	int size;
	cout << "Enter value of X0 : ";
	cin >> x0;
	cout << "Enter value of interval : ";
	cin >> interval;
	cout << "Enter number of values : ";
	cin >> size;
	cout << "Enter initial value of Y : ";
	cin >> y0;
	cout << "Final result : " << euler_result(y0, x0, size, interval) << endl;
	system("pause");
	return 0;
}


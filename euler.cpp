// euler.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
double find_y(double y0, double x0) {
	double result = x0 + y0;
	return result;
}

double euler_result(double y0, double x0, int size, double interval) {
	double result = 0;
	for (int i = 1 ; i < size; i++) {
		result = y0 + (interval*find_y(y0, x0));
		x0 = x0 + interval;
		y0 = result;
	}
	return result;
}
int main()
{
	double x0, y0, interval ;
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


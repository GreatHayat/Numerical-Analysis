// runga_kutta_2nd_order.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
double function(double y0, double x0) {
	double result = (y0 - x0)/(y0 + x0);
	
	return result;
}
double k1(double y0, double x0, double interval) {
	double result = interval*function(y0, x0);

	return result;
}
double k2(double y0, double x0, double interval) {
	double x = x0 + (interval / 2);
	double y = y0 + (k1(y0, x0, interval)/2);
	double result = interval * function(y , x);
	
	return result;
}

double euler_result(double y0, double x0, double xn, double interval) {
	double result = 0.0;
	while (x0 != xn) {
		result = y0 + (k1(y0, x0, interval) + k2(y0, x0, interval)) / 2;
		cout << "Result :" << result << endl;
		x0 = x0 + interval;
		y0 = result;
	}
	return result;
}
int main()
{
	double x0, y0, xn, interval;
	cout << "Enter value of X0 : ";
	cin >> x0;
	cout << "Enter value of interval : ";
	cin >> interval;
	cout << "Enter value of Xn : ";
	cin >> xn;
	cout << "Enter initial value of Y : ";
	cin >> y0;
	cout << "Final result : " << euler_result(y0, x0, xn, interval) << endl;
	system("pause");
	return 0;
}
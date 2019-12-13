#include <iostream>
#include "Polynomial.h"

using namespace std;

int main()
{
	try
	{
		cout << "Format: 1*x^2+1.5*x^0\n";
		Polynomial pol1;
		cout << "Enter first polynomial:\n";
		cin >> pol1;
		Polynomial pol2;
		cout << "Enter second polynomial:\n";
		cin >> pol2;
		cout << "Enter x:\n";
		double x;
		cin >> x;
		Polynomial pol3 = pol1 + pol2;
		cout << "Sum: " <<pol1+pol2;
	}
	catch (...)
	{
		cout << "Error...";
	}
}
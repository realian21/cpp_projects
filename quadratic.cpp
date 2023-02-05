/* Ian Lim
CMPSC 121-001
Date: 10/9/22
This program prompts the user for the coefficients
of a, b, and c of a quadratic function in the form
f(x) = ax^2 + bx + c and outputs the roots */

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
	double a; // double to store value of coefficient for x^2
	double b; // double to store value of coefficient for x
	double c; // double to store value of coefficient for constant
	double disc; // double to store value of discriminant
	double d; // double to store of -b/2a
	double f; // double to store value of sqrt(disc)/2a
	bool valid; // true or false for user input validation

	valid = false; // initialize valid to be false

	do {
		cout << "Enter the coefficients a, b, and c of a quadratic function: ";
		cin >> a >> b >> c;
		// the user inputs are valid if a does not equal zero
		if (a != 0) {
			valid = true;
		}
		else
			cout << "This is not a quadratic function." << endl;
	} while (!valid);

	disc = pow(b, 2) - 4 * a * c; // the discriminant is b^2 - 4ac

	// d is the left part of the quadratic formula -b/2a
	d =  -b / (2 * a);

	if (disc > 0) { // a positive discriminant gives two real roots
		f = sqrt(disc) / (2 * a);
		cout << fixed << setprecision(3) << "The two real roots are: " << d + f << " and " << d - f << endl;
	}
	else if (disc < 0) { // a negative discriminant gives two complex roots
		f = sqrt(-disc) / (2 * a);
		cout << fixed << setprecision(3) << "The two complex roots are: " << d << " + " << f << "i and " << d << " - " << f << "i" << endl;
	}
	else { // a zero discriminant gives a single real root
		if (d == 0)
			cout << fixed << setprecision(3) << "The real root is: " << -d << endl; // output zero instead of negative zero
		else
			cout << fixed << setprecision(3) << "The real root is: " << d << endl; // output d normally if not zero
	}

	return 0; // indicates the program ran successfully
}
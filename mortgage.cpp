/* Ian Lim
CMPSC 121-001
Date: 10/23/22
Mortgager Project
This program generates an amortization schedule for each month given user inputs
of the amount of money borrowed (principal), annual interest rate as a percentage,
and term of the loan in years. */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>

double monthlyMortgagePayment(double, double, int); // prototype function calculating monthly mortgage payment

int main() {
	double monthlyPayment; // double to store value of monthly mortgage payment
	double p; // double to store value of money borrowed (principal)
	double r; // double to store annual interest rate
	double i; // double to store monthlt interest rate
	int t; // integer to store term of loan
	int month; // integer to store current month
	int monthMax; // integer to store final month
	double balance; // double to store current balance
	double interest; // double to store current interest
	double totalInterest; // double to store total interest
	std::string filename; // string to store output file name

	std::cout << "Enter amount borrowed (principal): $";
	std::cin >> p;

	std::cout << "Enter the annual percentage rate (i.e., 3.5 for 3.5%): ";
	std::cin >> r;

	std::cout << "Enter the number of years (term): ";
	std::cin >> t;

	std::cout << "Enter the name of the file in which to leave the ouput: ";
	std::cin >> filename;

	r = r / 100; // turns percentage into a decimal
	i = r / 12; // gives monthly rate value of annual rate divided by 12
	monthMax = t * 12; // calculates how many months based on year times 12

	monthlyPayment = monthlyMortgagePayment(p, i, monthMax); // calls monthly mortgage payment function

	balance = p; // initialize balance to principal

	totalInterest = p * i; // initialize total interest to principal * monthly rate

	std::ofstream output;

	output.open(filename); // open output file

	output << "Principal: $" << p << std::endl; // outputs principal
	output << "Yearly rate: " << r << std::endl; // outputs annual rate
	output << "Term (years): " << t << std::endl; // outputs lenght of loan in years
	output << "Monthly Payment: $" << std::fixed << std::setprecision(2) << monthlyPayment << std::endl; // outputs monthly payment
	output << std::endl;

	// outputs headers for columns
	output << std::setw(5) << "Month" << std::setw(12) << "Balance" << std::setw(12) << "Interest" << std::setw(12) << "Payment" << std::endl;

	// outputs month 0, initial balance and interest
	output << std::setw(5) << 0 << std::setw(2) << '$' << std::fixed << std::setprecision(2) << std::setw(10) << balance << std::setw(2) << '$' << std::setw(10) << totalInterest << std::setw(2) << '$' << std::setw(10) << monthlyPayment << std::endl;

	// for loop to output balance and interest for each consecutive month
	for (month = 1; month < monthMax; month++) {
		balance = balance + (balance * i) - monthlyPayment;
		interest = balance * i;
		totalInterest = totalInterest + interest;

		output << std::setw(5) << month << std::setw(2) << '$' << std::fixed << std::setprecision(2) << std::setw(10) << balance << std::setw(2) << '$' << std::setw(10) << interest << std::setw(2) << '$' << std::setw(10) << monthlyPayment << std::endl;
	}

	// outputs the final balance after loan is paid off
	output << std::setw(5) << monthMax << std::setw(2) << '$' << std::fixed << std::setprecision(2) << std::setw(10) << balance + (balance * i) - monthlyPayment << std::endl;

	output << std::endl;

	// outputs the principal, total payment, and total interest paid
	output << "Borrowing $" << std::fixed << std::setprecision(2) << p << ", a total of $" << monthlyPayment * monthMax << " payment was made and the total interest paid was $" << totalInterest << std::endl;

	return 0; // indicates the program ran successfully
}

// function that calculates the monthly payment to be made based on principal, monthly rate, and term in months
double monthlyMortgagePayment(double p, double i, int t) {
	double monthlyPayment; // double to store value of monthly payment

	// formula for calculating monthly payment
	monthlyPayment = (p * i) * pow(1 + i, t) / (pow(1 + i, t) - 1);

	return monthlyPayment; // returns monthly payment to main
}
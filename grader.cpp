/* Ian Lim
CMPSC 121-001
Date: 12/11/22
Grader Project
This program takes an input file of up to 100 final scores, and then outputs into a
file: the mean, the standard deviation, the maximum score, the minimum score, and the
range. It also determines the letter grade of each score based on the mean and standard
deviation and counts how many of each letter grade results from the input file */

#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>

double mean(double const [], int); // prototype function to calculate mean
double standardDeviation(double const [], int, double); // prototype function to calculate standard deviation
double minimum(double const [], int); // prototype function to find miniimum value
double maximum(double const [], int); // prototype function to find maximum value
void gradeTally(double const [], int [], int, double, double); // prototype function to tally each letter grade

int main() {
	int arraySize; // integer to store value of grade array size
	double m; // double to store value of the mean
	double s; // double to store value of the standard deviation
	double min; // double to store value of the minimum
	double max; // double to store value of the maximum
	double range; // double to store value of the range
	double scoreArray[100]; // array to store up to 100 scores
	int tallyArray[11]; // array to store 11 different letter grades

	// letter grade array assigns a letter grade ranging from F to A+ to each index
	std::string letterGradeArray[] = { "A ", "A-", "B+", "B ", "B-", "C+", "C ", "C-", "D+", "D ", "F " };

	std::string inFile; // string to store user input for input file name
	std::string outFile; // string to store user input for output file name

	std::ifstream input; // name of input file stream
	std::ofstream output; // name of output file stream

	arraySize = 0; // initializes grade array size to be zero

	for (int i = 0; i < 11; i++) {
		tallyArray[i] = 0; // initializes all letter grade tallies to be zero
	}

	std::cout << "Enter the name of the file in which to read the input: ";
	std::cin >> inFile;

	input.open(inFile);

	if (input.fail()) {
		std::cout << "Cannot open " << inFile << std::endl;
		return 1;
	}

	std::cout << "Enter the name of the file in which to put the output: ";
	std::cin >> outFile;

	input >> scoreArray[arraySize];

	while (!input.fail()) {
		arraySize++;
		input >> scoreArray[arraySize];
	}

	input.close();

	m = mean(scoreArray, arraySize); // mean is calculated by calling the mean function
	s = standardDeviation(scoreArray, arraySize, m); // standard deviation is calculated by calling the standard deviation function
	min = minimum(scoreArray, arraySize); // minimum score is found using the minimum function
	max = maximum(scoreArray, arraySize); // maximum score is found using the maximum function
	range = max - min; // range is the maximum score minus the minimum score
	gradeTally(scoreArray, tallyArray, arraySize, m, s); // the letter grades are counted by calling the gradeTally function

	output.open(outFile);

	output << std::fixed << std::setprecision(2) << "Mean: " << m << std::endl;
	output << "Standard Deviation: " << s << std::endl;
	output << "Maximum: " << max << std::endl;
	output << "Minimum: " << min << std::endl;
	output << "Range: " << range << std::endl;
	output << "Grade" << std::setw(17) << "Number_of_scores" << std::endl;

	for (int i = 0; i < 11; i++) {
		output << std::left << std::setw(6) << letterGradeArray[i] << tallyArray[i] << std::endl;
	}

	output.close();

	std::cout << "The output can be found in \"" << outFile << "\"" << std::endl;

	return 0; // indicates the program ran successfully
}

/* This function calculates the mean. It takes the score array and sums up all of the elements of the array
and then divides it by the array size */
double mean(double const scoreArray[], int arraySize) {
	double m; // double to store the value of the mean
	double total; // double to store the value of the sum

	total = 0; // the total is initialized to be zero

	for (int i = 0; i < arraySize; i++) {
		total = total + scoreArray[i]; // the ith element of the score array is added to the sum
	}

	m = total / arraySize; // the mean is equal to the total divided by the size of the array

	return m; // return the mean to main
}

/* This function calculates the standard deviation. It finds the sum of the square of the subtraction of the
mean from the ith element of the score array, divides the sum by the array size, and takes the square root of
the result */
double standardDeviation(double const scoreArray[], int arraySize, double m) {
	double s; // double to store value of the standard deviation
	double total; // double to store value of the sum

	total = 0; // the total is initialized to be zero

	for (int i = 0; i < arraySize; i++) {
		// the square of the subtraction of the mean from the ith element of the score array is added to the sum
		total = total + pow(scoreArray[i] - m, 2);
	}

	s = sqrt(total / arraySize); // the SD is equal to the square root of the total divided by the size of the array

	return s; // return the standard deviation to main
}


/* This function finds the minimum score from the score array. It initializes the minimum to be the first score
and replaces the minimum if a lower score is found */
double minimum(double const scoreArray[], int arraySize) {
	double min; // double to store the value of the minimum score

	min = scoreArray[0]; // the minimum score is initialized to be the first score

	for (int i = 1; i < arraySize; i++) {
		if (scoreArray[i] < min) {
			// the minimum score is assigned the value of the current array element if it is lower
			min = scoreArray[i];
		}
	}

	return min; // return the minimum score to main
}

/* This function finds the maximum score from the score array. It initializes the maximum to be the first score
and replaces the maximum if a higher score is found */
double maximum(double const scoreArray[], int arraySize) {
	double max; // double to store the value of the maximum score

	max = scoreArray[0]; // the maximum score is initialized to be the first score

	for (int i = 1; i < arraySize; i++) {
		if (scoreArray[i] > max) {
			// the maximum score is assigned the value of the current array element if it is higher
			max = scoreArray[i];
		}
	}

	return max; // return the maximum score to main
}

/* This function determines counts how many of each letter grade is found from the score array. It determines
what letter grade the current score is based on the mean and standard deviation and tallies the tally array
accordingly */
void gradeTally(double const scoreArray[], int tallyArray[], int arraySize, double m, double s) {
	double x; // double to store the current score

	for (int i = 0; i < arraySize; i++) {
		x = scoreArray[i]; // x is the ith element of the score array

		if (x >= m + (double)4 / (double)3 * s) {
			tallyArray[0]++; // increment letter grade A
		}
		else if (x >= m + s) {
			tallyArray[1]++; // increment letter grade A-
		}
		else if (x >= m + (double)2 / (double)3 * s) {
			tallyArray[2]++; // increment letter grade B+
		}
		else if (x >= m + (double)1 / (double)3 * s) {
			tallyArray[3]++; // increment letter grade B
		}
		else if (x >= m) {
			tallyArray[4]++; // increment letter grade B-
		}
		else if (x >= m - (double)1 / (double)3 * s) {
			tallyArray[5]++; // increment letter grade C+
		}
		else if (x >= m - (double)2 / (double)3 * s) {
			tallyArray[6]++; // increment letter grade C
		}
		else if (x >= m - s) {
			tallyArray[7]++; // increment letter grade C-
		}
		else if (x >= m - (double)4 / (double)3 * s) {
			tallyArray[8]++; // increment letter grade D+
		}
		else if (x >= m - (double)5 / (double)3 * s) {
			tallyArray[9]++; // increment letter grade D
		}
		else {
			tallyArray[10]++; // increment letter grade F
		}
	}
}
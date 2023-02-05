/* Ian Lim
CMPSC 121-001
Date: 11/20/22
Bubble Sorter
This program uses a simple bubble sort to sort an array of up
to 100 integers in ascending order. It prompts the user for an input
file that contains up to 100 integers, reads the integers into an array,
sorts the array using a simple bubble sorting algorithm, and outputs the
name of the output file, the number of integers in the array, and the number
of swaps to sort the array */

#include <iostream>
#include <iomanip>
#include <fstream>

int bubbleSorter(int[], int); // prototype the function to bubble sort array

int main() {
	int itemArray[100]; // array to store 100 elements
	int arraySize; // integer to store size of the array
	int lines; // integer to store number of output lines
	int remainder; // integer to store remainder elements
	int element; // integer to store index of array outside loop count
	int swap; // integer to store number of swaps

	std::string inFile; // string to store name of input file
	std::string outFile; // string to store name of output file

	std::ifstream input; // input file stream name
	std::ofstream output; // output file stream name

	std::cout << "Enter the name of the file in which to read the input: ";
	std::cin >> inFile;

	input.open(inFile);

	if (input.fail()) {
		std::cout << "Cannot open " << inFile << std::endl;

		return 1;
	}

	std::cout << "Enter the name of the file in which to put the output: ";
	std::cin >> outFile;

	arraySize = 0;

	input >> itemArray[arraySize];

	while (!input.fail()) { // reads to the end of the input file
		arraySize++; // increments size of the array

		input >> itemArray[arraySize]; // reads each input into the array
	}

	input.close();

	swap = bubbleSorter(itemArray, arraySize); // call the bubble sorting function

	output.open(outFile);

	lines = arraySize / 10; // the number of output lines is the result of integer division by 10
	remainder = arraySize % 10; // the remainding elements after the lines is the result of modulo 10

	element = 0; // initialize the array index to be zero

	for (int i = 0; i < lines; i++) { // for each line of the output

		for (int j = 0; j < 10; j++) {

			output << std::setw(6) << itemArray[element]; // output the current index array element

			element++; // increment the array index
		}
		output << std::endl;
	}

	for (int i = 0; i < remainder; i++) { // for the last line of the output

		output << std::setw(6) << itemArray[element]; // output the current index array element

		element++; // increment the array index
	}

	output.close();

	std::cout << "The output can be found in " << outFile << std::endl;
	std::cout << "The number of integers in the input file: " << arraySize << std::endl;
	std::cout << "The number of swaps required to sort the file: " << swap << std::endl;

	return 0; // indicates the program ran sucessfully
}

/* This function sorts an array through bubble sorting. It does this by comparing the current index
arrary element to the next index array element. If the current index array element is greater than the
next index array element, a temporary variable is assigned the value of the current index array element,
then the current index array element is assigned the value of the next index array element, and the next
index array element is assigned the value of the temporary variable, swapping the values. This is done
for all elements of the array with a nested loop that does one round for each array index */
int bubbleSorter(int itemArray[], int arraySize) {
	int swap; // integer to store value of how many element swaps

	swap = 0; // initialize value of swap to be zero

	for (int i = 0; i < arraySize - 1; i++) { // loop for all rounds of array elements

		for (int j = 0; j < arraySize - 1 - i; j++) { // single round of bubble sort for current array element

			if (itemArray[j] > itemArray[j + 1]) { // if the current element is greater than the next
				int temp = itemArray[j]; // integer to store temporary value is assigned current element value
				itemArray[j] = itemArray[j + 1]; // current element is assigned value of next element
				itemArray[j + 1] = temp; // next element is assigned value of temporary variable

				swap++; // increment swap counter
			}
		}
	}

	return swap; // return swap to main function
}
/* Selection Sorter
This program uses a simple selection sort to sort an array of up
to 100 integers in ascending order. It prompts the user for an input
file that contains up to 100 integers, reads the integers into an array,
sorts the array using a simple selection sorting algorithm, and outputs the
name of the output file, the number of integers in the array, and the number
of swaps to sort the array */

#include <iostream>
#include <iomanip>
#include <fstream>

int selectionSorter(int[], int); // prototype the function to selection sort array

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

	swap = selectionSorter(itemArray, arraySize); // call the selection sorting function

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

/* This function sorts an array through selection sorting. It does this by checking each index array element for the
least value. It first assigned the leaest value to be the current index array element and then replaces the least value
with a value in a nested loop if it is lower than the current smallest value. Once doing this is increments the swap counter
and this round is repeated for all remaining array elements after the first element. */
int selectionSorter(int itemArray[], int arraySize) {
	int swap; // integer to store the number of element swaps

	swap = 0; // initialize value of swap to be zero

	for (int i = 0; i < arraySize - 1; i++) { // loop for all rounds of array elements

		int smallest = i; // integer to store lowest value is initialized to current index

		for (int j = i + 1; j < arraySize; j++) { // loop for other elements beyond the current index
			if (itemArray[smallest] > itemArray[j]) { // if any element in the nested loop is smaller than the current index for smallest
				smallest = j; // smallest is replaced with the new index

				swap++; // swap counter in incremented
			}
		}

		int temp = itemArray[i]; // integer to store temporary value is assigned value of array at current index i
		itemArray[i] = itemArray[smallest]; // current index array element is assigned value of array at index smallest
		itemArray[smallest] = temp; // array element at index smallest is assigned temporary value
	}

	return swap; // swap is returned to main function
}

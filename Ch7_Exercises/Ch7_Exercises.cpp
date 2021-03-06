#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cassert>
#include <array>

#ifndef NDEBUG 

#endif

int sumTo(const int value);

//void printEmployeeName(const Employee &employee);

int& minMax(const int input);

int getIndexOfLargestValue(const int *array, const int size);

const int& getElement(const int *array, const int index);

void print(char *value);
void print(int value);

void print2(int x, int y = 666);

int getNumber();
int getSecondNumber();
char getOperation();

int add(int, int);
int subtract(int, int);
int divide(int, int);
int multiply(int, int);


int getNumber() {
	int input1;
	std::cout << "enter a number " << std::endl;
	std::cin >> input1;
	return input1;
}

char getOperation() {
	char op;
	std::cout << "enter an operation + - * / " << std::endl;
	std::cin >> op;
	return op;
}

int add(int x, int y) {
	return x + y;
}
int subtract(int x, int y) {
	return x - y;
}

int multiply(int x, int y) {
	return x * y;
}

int divide(int x, int y) {
	return x / y;
}


//arithmeticFcn is a pointer to a function that takes two arguments, and returns and integer
typedef int (*arithmeticFcn) (int,int);

struct arithmeticStruct {
	char mathOp;
	arithmeticFcn fcn;
};

// put your static array here, note: that it's 2d
static arithmeticStruct arithmeticArray[] = { {'+', add}, {'-', subtract}, {'*', multiply}, {'/', divide} };

arithmeticFcn getArithmeticFunction(char op) {
	/*switch(op)
	{
		default: //default will be add
			case '+': return add;
			case '-': return subtract;
			case '*': return multiply;
			case '/': return divide;
	} */

	for (const arithmeticStruct x : arithmeticArray) {
		if (x.mathOp == op) return x.fcn;
	}
}

void print2(int x , int y ) {
	std::cout << " x is " << x << std::endl;
	std::cout << " y is " << y << std::endl;
}

void print(char *value) {
	std::cout << "char " << value;

}

void print(int value) {
	std::cout << "int " << value;
}


int foo() {
	return 5;
}

int factorial(int n) {
	if (n == 0) return 1;
	else return n * factorial(n - 1);
}

//Not recursive
void indivSum(int n) {
	std::string str_var = std::to_string(n);
	int size = str_var.length();
	int y(0);
	for (const auto &n : str_var) {
		int a = n - '0';
		y += a;
	}
	std::cout << y << '\n';
}

//recursive
int indivSum2(int n) {

	//convert number to a string
	std::string numberToString = std::to_string(n);
	std::vector<char> stringToVector;

	//base case: if there's only one digit, convert it back, then return the integer
	if (numberToString.length() == 1) {
		return n;
	}

	// load vector with characters in string
	for (int i = 0; i < numberToString.length(); ++i)
		stringToVector.push_back(numberToString[i]);

	// save the first digit
	int firstDigit;
	firstDigit = stringToVector[0] - '0';

	// remove first digit
	stringToVector.erase(stringToVector.begin());

	//convert the rest of the string to an integer
	// syntax concatInteger << 1 << 2 << 3 << 4
	std::ostringstream concat;

	for (int i = 0; i < stringToVector.size(); ++i)
		concat << stringToVector[i] - '0';

	std::stringstream concatString(concat.str());

	int convertBackToInt;
	concatString >> convertBackToInt;

	//add the digit with recursive call of function
	return firstDigit + indivSum2(convertBackToInt);
}

void findCharactersInString() {
	std::string hello = "Hello, world!";
	std::cout << "Enter a letter: ";

	char ch;
	std::cin >> ch;

	int index = hello.find(ch);

	if (index == -1)
		std::cout << " character was not found " << '\n';
	else
		std::cout << ch << " was found at index " << index << '\n';
}

void enterAnIndex() {
	std::string hello = "hello, world!";

	int index;

	do {
		std::cout << "Enter an index: ";
		std::cin >> index;

		std::cout << "Letter #" << index << " is " << hello[index] << std::endl;
	} while (index < 0 || index >= hello.size());
}

int getArrayValue(const std::array<int, 10> &array, int index) {

	//this is a little cryptic
	//assert(index >= 0 && index <= 9);

	// so add one that makes sense
	assert(index && "chracter could not be found");

	return array[index];
}

int main(int argc, char *argv[])
{


	//std::cout << foo << '\n'; // just prints the address of foo
	//because of this, you can initialize a function pointer with the name of the function
	//int(*blah)() = foo;


	//print(0);
	//print2(1);
	//print2(1, 2);

	/*
	int x = getNumber();
	int y = getNumber();
	char z = getOperation();

	*/

	//arithmeticFcn fcn = getArithmeticFunction(z);
	//std::cout << x << ' ' << z << ' ' << y << " = " << fcn(x, y) << '\n';

	//std::cout << factorial(5) << '\n';


	//std::cout << " > " << indivSum2(93427) << '\n';

	//findCharactersInString();
	//enterAnIndex();


	std::array<int, 10> array1;
	array1 = { 1,3,4,5 };

	//getArrayValue(array1, -3);
	if (argc <= 1) {
		if (argv[0])
			std::cout << "Usage: " << argv[0] << " <number>" << '\n';
		else
			std::cout << "Usage: <program name> <number>" << '\n';
		exit(1);
	}

	std::stringstream convert(argv[1]); // setup a stringstream variable named convert initialized with input from argv[1]

	int myint;
	if (!(convert >> myint)) // do the conversion
		myint = 0;

	std::cout << "Got integer: " << myint << '\n';

    return 0;
}


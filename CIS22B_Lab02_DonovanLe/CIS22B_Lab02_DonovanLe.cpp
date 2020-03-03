/*
Donovan Le Lab 02
CIS22B Goel
*/

/*
1. Entire program must be able to loop
	a. PLace main program into a while loop
2. Prompt user for which test cases they want
	a. User's choice will be taken as an integer
3. User's choice will be placed into a switch case
	a. 4 different cases depending on user's choice
4. Case 1 is string length, which will be in its own function
	A. User is presented with a prompt to enter a string
	a. In order to count length of string, a variable will continue to count as long as there is no NULL character
	b. Once the variable hits a NULL character, the count will be returned
5. Case 2 is copying a string to a character array
	A. User is presented with a prompt to enter two strings
	a. A for loop will be used to traverse through the array
	b. Copy each letter of the source word to the destination
	c. Then present user with the destination after the copy has been done
6. Case 3 is adding a string to the end of another
	A. User must enter first the string they want to add to, then the string that will be added
	a. The length of the string user wishes to add to must be known
		1. Therefore at the end of that string the new one can be added
	b. A for loop will be used to copy each letter of the added string to the end of destination string
7. Case 4 is comparing two strings
	A. User is presented with a prompt to enter two strings
	a. Assign the strings passed into the function as unsigned chars
		1. Able to read the strings as numbers
	b. Use while loop to traverse through both strings
		1. If a NULL character is hit, the while loop will break
		2. While it is traversing, the count of each string is incrementing
	c. After the while loop is broken the count of each string is subtracted from eachother
	d. If the diff is greater than 0 the first string is longer
	e. If the diff is less than 0 the second string is longer
	f. If there is no 0, the strings are equal
	g. The user is presented with the results

*/

#include <iostream>
#include <fstream>
#include <string>
#include <istream>

using namespace std;

int stringLength(const char* str1);
void stringNCopy(char* des, const char* src);
void stringNAdd(char* des, const char* src);
void stringNCompare(const char* str1, const char* str2);

int main()
{
	const int wordSize = 50;
	char firstString[wordSize];
	char secondString[wordSize];
	string userString;
	int userChoice;
	char repeat = 'y';

	while (repeat == 'y') {
		cout << "Please select an option(number) to which you would like to test" << endl;
		cout << "1.String Length\n2.String Copy\n3.String Add\n4.String Compare" << endl;
		cin >> userChoice;
		switch (userChoice) {
		case 1:	//User selecting "1" would bring them to string length function
			cout << "Enter a string to find the length of:" << endl;
			cin >> firstString;
			cout << stringLength(firstString) << endl;
			break;
		case 2: //User selecting "2" would bring them to string copy function
			cout << "Enter a string to copy to the character array:" << endl;
			cin >> firstString;
			cout << "Enter a second string to be overwritten by the first" << endl;
			cin >> secondString;
			stringNCopy(firstString, secondString);
			break;
		case 3: //User selecting "3" would bring them to string add function
			cout << "Enter a string in which you would like to add to:" << endl;
			cin >> firstString;
			cout << "Enter a string to add:" << endl;
			cin >> secondString;
			stringNAdd(firstString, secondString);
			break;
		case 4: //User selecting "4" would bring them to string compare function
			cout << "Enter first string:" << endl;
			cin >> firstString;
			cout << "Enter second string to compare to first string:" << endl;
			cin >> secondString;
			stringNCompare(firstString, secondString);
			break;
		}
		cout << "Would you like to run more test?(y/n)" << endl;
		cin >> repeat;
	}
	system("pause");
	
	
	return 0;
}

int stringLength(const char* str1) {
	int count = 0;
	int i = 0;
	while (str1[i] != '\0') { //Count until string hits a NULL
		count++;
		i++;
	}
	return count;
}
void stringNCopy(char* des, const char* src) {
	int i = 0;
	int size = 50; //MAX size of char array length
	cout << "Destination: " << des << endl;
	cout << "Source: " << src << endl;
	for (i = 0; i < size; i++) {  //Overwrite the destination word letter by letter
		des[i] = src[i];
	}
	cout << "After copy destination: " << des << endl;
}
void stringNAdd(char* des, const char* src) {
	int srcLen = stringLength(src);
	int desLen = stringLength(des);
	cout << "Destination: " << des << endl;
	cout << "What you want to add: " << src << endl;
	for (int i = 0; i < srcLen + 1; i++) {
		des[desLen + i] = src[i]; //After NULL add the source word
	}
	cout << "Full string: " << des << endl;
}
void stringNCompare(const char* str1, const char* str2) {
	const unsigned char *t1 = (const unsigned char *)str1;
	const unsigned char *t2 = (const unsigned char *)str2;

	int x = stringLength(str1);
	int y = stringLength(str2);

	int diff = x - y; //Get difference of character lengths
	if (diff > 0) {
		cout << "First string is greater than second string" << endl;
	}
	else if (diff < 0) {
		cout << "Second string is greater than first string" << endl;
	}
	else {
		cout << "Both strings are equal" << endl;
	}
}
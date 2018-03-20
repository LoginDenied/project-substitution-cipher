#include <iostream>
#include <string>
#include <array>

using namespace std;

char input[1000];
char output[1000];
int displacementValue;

char alphabetArrayUppercase[] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };
char alphabetArrayLowercase[] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };

void getInput()
{
	cout << "Please enter the string to be encoded" << endl;
	cout << "Note: Ths string can only have a maximum of 1000 char and needs to terminate in a @" << endl;
	cout << "Note: Any spaces will be eliminated through this encoding process" << endl;
	int position = 0;
	do
	{
		cin >> input[position];
		position++;
	} while (input[position-1] != '@');
	cout << "This program will swap every letter for the letter x number of places to the right" << endl;
	cout << "For example: A + 3 places will be D" << endl;
	cout << "Please input x" << endl;
	cin >> displacementValue;
}

void replaceLetters(char input[])
{
	string replacement = "FALSE";

	for (int i = 0; i < 1000; i++) // Running through the whole input string
	{
		for (int j = 0; j < 26; j++) // Checking against the arrays
		{
			if (input[i] == alphabetArrayUppercase[j])
			{
				output[i] = alphabetArrayUppercase[(j + displacementValue)%26];
				replacement = "TRUE";
			}
			else
			{
				if (input[i] == alphabetArrayLowercase[j])
				{
					output[i] = alphabetArrayLowercase[(j + displacementValue) % 26];
					replacement = "TRUE";
				}
			}
		}

		if (replacement == "FALSE")
		{
			output[i] = input[i];
		}
		replacement = "FALSE";
	}
}

int main()
{
	getInput();
	replaceLetters(input);
	cout << "String has been encoded:" << endl;
	cout << output << endl;
	cout << "-PROGRAM END-" << endl;
    
	return 0;
}

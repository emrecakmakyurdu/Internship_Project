// Internship_Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//#include "stdafx.h"

#include "ApplyAlgorithm.h"

#include <math.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main()
{
	int n = 100000;
	int t = 0, i = 0, c = 0;

	cout << "Enter the type of the array to be initialized. :" << endl;
	cout << "0. Integer " << endl;
	cout << "1. Float \n2. Char " << endl;
	cout << "3. Double \n" << endl;

	cin >> t;

	while (t < 0 || t > 3)
	{
		cout << "Enter a valid number : " << endl << endl;
		cin >> t;
	}
	if (t == 0) {
		cout << "Selected Type : Integer" << endl << endl;
		ApplyAlgorithm<int> A(n, t);
		A.Start();
	}
	else if (t == 1) {
		cout << "Selected Type : Float" << endl << endl;
		ApplyAlgorithm<float> A(n, t);
		A.Start();
	}
	else if (t == 2) {
		cout << "Selected Type : Char" << endl << endl;
		ApplyAlgorithm<char> A(n, t);
		A.Start();
	}
	else if (t == 3) {
		cout << "Selected Type : Double" << endl << endl;
		ApplyAlgorithm<double> A(n, t);
		A.Start();
	}
	cout << endl;

	return 0;
};



// PerfectNumbers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//Arin Bindra
//Perfect Numbers

#include <iostream>
#include <vector>
#include <set>
#include <iterator>

using namespace std;

/*-------------------------------------------------------------------------------------------------------------------
	The following function takes a number as an input and sees if it is a perfect number

*/

int main()
{
	int n;
	int result = 0;
	int size;
	set<int> factors;

	bool correct = false;

	cout << "Welcome to the Perfect Number test\n\n";

	while (correct != true)
	{
		cout << "Please enter a positive integer. (Number must be greater then 2)\n";
		cin >> n;

		if (n > 2)
		{
			correct = true;
		}
	}

	/*
		The following code iterates through every value under half to n as i, and if i is a factor of n it is added into the factors set
		and its value is added to the sum of factors.
	*/

	for(int i = 1; i < ((n/2) + 1); i++)
	{
		if (n % i == 0)
		{
			factors.insert(i);
			result = result + i;
		}
	}


	if (result == n)
	{
		cout << "\n\n" << n << " is a Perfect Number" << endl;
		cout << "The total sum of " << n << "'s factors are " << result << endl;
		cout << n << "'s factors are:" << endl;

		set<int>::iterator itr;

		for (itr = factors.begin(); itr != factors.end(); itr++)
		{
			cout << *itr << " ";
		}

		cout << "\n\n";
	}
	else
	{
		cout << "\n\n" << n << " is NOT a Perfect Number" << endl;
		cout << "The total sum of " << n << "'s factors are " << result << endl;
		cout << n << "'s factors are:" << endl;

		set<int>::iterator itr;

		for (itr = factors.begin(); itr != factors.end(); itr++)
		{
			cout << *itr << " ";
		}

		cout << "\n\n";
	}
}

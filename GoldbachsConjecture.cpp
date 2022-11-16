//GoldbachsConjecture.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//Arin Bindra
//Goldbachs Conjecture

#include <iostream>
#include <vector>

using namespace std;

/*-------------------------------------------------------------------------------------------------------------------
	The following function takes an even integer greater then 2 and checks if it can be expressed as a sum of 2 primes
*/

int main()
{
	int n;
	int r1;
	int r2 = 0;

	bool correct = false;
	
	cout << "Welcome to the Goldbachs Conjecture theory test\n\n";

	while (correct != true)
	{
		cout << "Please enter an even number. (Number must be greater then 2)\n";
		cin >> n;

		if ((n > 2) && (n % 2 == 0))
		{
			correct = true;
		}
	}

	/*
		The following code uses the seive of erathosthenes to set all of the prime values as true in the array is_prime upto n.
	*/

	vector<bool> is_prime(n + 1, true);

	is_prime[0] = false;
	is_prime[1] = false;

	for (unsigned i = 2; i <= n; i++)
	{
		if (is_prime[i] != false)
		{
			unsigned j = i + i;

			while (j <= n)
			{
				is_prime[j] = false;

				j = j + i;
			}
		}
	}

	/*
		The following code uses a while loop to first check if j is a prime number, and then finds the difference between n and j.
		If the difference is also a prime number it will save the value and break the loop, otherwise it will check the next prime number.
	*/

	bool proved = false;
	int j = 0;

	while((proved != true) || (j <= n))
	{
		if (is_prime[j] == true)
		{
			r1 = j;

			int diff = n - j;

			if (is_prime[diff] == true)
			{
				r2 = diff;
				proved = true;
			}
		}

		if (proved == true)
		{
			break;
		}

		j++;
	}

	if (r2 != 0)
	{
		cout << "\n\nGoldbachs Conjecture theorum is TRUE for " << n << endl;
		cout << r1 << " + " << r2 << " = " << n << endl;

		if (r1 == r2)
		{
			cout << r1 << " is a prime number.\n\n" << endl;
		}
		else
		{
			cout << "Both " << r1 << " and " << r2 << " are both prime numbers.\n\n" << endl;
		}
	}
	else
	{
		cout << "Goldbachs Conjecture theorum is FALSE for " << n << endl;
		cout << "There are no 2 prime numbers which sum to " << n << "\n\n" << endl;
	}
}

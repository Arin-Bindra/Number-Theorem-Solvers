// PrimeCounting_SieveOfEratosthenes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Arin Bindra

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	unsigned max = 100000;

	vector<bool> is_prime(max + 1, true);


		is_prime[0] = false;
		is_prime[1] = false;



	unsigned nprime = 0;

	for (unsigned i = 2; i <= max; i++)
	{
		if (is_prime[i] != false)
		{
			unsigned j = i + i;

			while (j <= max)
			{
				is_prime[j] = false;

				j = j + i;
			}
		}
	}

	for (unsigned n = 0; n <= max; n++)
	{
		if (is_prime[n] == true)
		{
			nprime++;
		}
	}

	cout << "The number of prime numbers between 2 and " << max
		<< " is " << nprime << endl;
}
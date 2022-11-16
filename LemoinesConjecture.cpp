// LemoinesConjecture.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//Arin Bindra
//Lemoines Conjecture

#include <iostream>
#include <vector>

using namespace std;

/*-------------------------------------------------------------------------------------------------------------------
	The following function takes an odd integer greater than 5 and checks if it can be expressed as the sum an odd prime number and an even semi prime.
*/

int main()
{
	int n;
	int r1;
	int r2 = 0;
	int s1;
	int s2;

	bool correct = false;

	cout << "Welcome to the Lemoines Conjecture theory test\n\n";

	while (correct != true)
	{
		cout << "Please enter an odd number. (Number must be greater then 5)\n";
		cin >> n;

		if ((n > 5) && (n % 2 != 0))
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
		If the difference is a semi prime number it will save the value and break the loop, otherwise it will check the next prime number.

		the differnce value is checked to be a semi prime number through a while loop which first checks if the value z is a prime number, then if
		the remainder of diff/z is zero and also a prime number, the semi prime value (diff) will be saved aswell as its two prime products.
	*/

	bool proved = false;
	int j = 3;

	while ((proved != true) || (j <= n))
	{
		if (is_prime[j] == true)
		{
			r1 = j;
			int diff = n - j;
			int z = 0;

			while(z <= n)
			{
				if (is_prime[z] == true)
				{
					if (diff % z == 0)
					{
						int p1 = diff / z;

						if (is_prime[p1] == true)
						{
							r2 = diff;
							s1 = z;
							s2 = p1;
							proved = true;
							break;
						}
					}
				}
				z++;
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
		cout << "\n\nLemiones Conjecture theorum is TRUE for " << n << endl;
		cout << r1 << " + " << r2 << " = " << n << endl;

		cout << r1 << " is an odd prime number and " << r2 << " is a semi prime number." << endl;
		cout << r2 << " is a product of " << s1 << " and " << s2 << " which are both prime numbers.\n\n" << endl;

	}
	else
	{
		cout << "\n\nLemiones Conjecture theorum is FALSE for " << n << endl;
		cout << "There is not an odd prime number greater than 5 and semi prime number which sum to " << n << "\n\n" << endl;
	}
}
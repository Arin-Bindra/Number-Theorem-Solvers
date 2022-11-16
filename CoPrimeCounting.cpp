// CoPrimeCounting.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//Arin Bindra
//Euler's Totient Function method

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <iterator>
#include <cmath>

using namespace std;

/*-------------------------------------------------------------------------------------------------------------------
The following function finds a particular values prime factors, and calculates it totient value.

*/
unsigned totient(unsigned x)
{
	unsigned totient_value = x;
	set<unsigned> prime_factors;
	unsigned count;

	/*-------------------------------------------------------------------------------------------------------------------
	The following loop finds a values prime factors and inserts them into a set.

	This is achived by iterating through each value smaller then x, and checking if there is a remander of zero between
	the two. If the remainder between the two values are zero, the value is then further checked to see if it is a prime
	number. This is done by adding a count value which signifies how many numbers the value is divisable by. The nested
	for loop iterates through every value smaller then i and if there are only 2 numbers it is divisable by with a
	remainder of zero it is recorded to be a prime factor of x, and is further added into the prime_factors set.
	*/
	for (unsigned i = 1; i <= x; i++)
	{
		count = 0;

		if (x % i == 0)
		{
			for (unsigned j = 1; j <= i; j++)
			{
				if (i % j == 0)
				{
					count++;
				}
			}
		}

		if (count == 2) 
		{
			prime_factors.insert(i);
		}
	}

	/*-------------------------------------------------------------------------------------------------------------------
	The following loop finds a values prime factors and inserts them into a set.

	This is achieved by pluggin in all of x's prime factors from the prime_factors set and plugging them into Euler's
	Totient equation, and then returning the totient value. The nested for loop iterates through each of value i's
	prime factors and converts them to a double type in order to complete part of Euler's Totient formula.
	*/

	set<unsigned>::iterator it;
	unsigned totient;
	double itD;
	double valueD = 1;
	double noD;

	for (it = prime_factors.begin(); it != prime_factors.end(); ++it)
	{
		itD = (double)*it;

		valueD = valueD * (1.0 - (1.0 / itD));
	}

	noD = round((double(x)) * valueD);

	totient = (unsigned)noD;

	return totient;
}


int main()
{
	unsigned N;
	bool correct = false;

	while (correct != true)
	{
		cout << "Please enter a number which you would like to find the number of coprimes upto. (Number must be greater then 1)\n";
		cin >> N;

		if (N > 1)
		{
			correct = true;
		}
	}

	unsigned max = N + 1;
	unsigned n_coprime = 0;

	vector<bool> is_coprime(max * max, false);
	vector<unsigned> totient_values(max, 1);

	/*-------------------------------------------------------------------------------------------------------------------
	The following loop inserts each value of i's prime factors going up to the maximum number N.
	
	This is achieved by starting off with the smallest prime number 2, and adding the value 2 into each prime number set
	that is a multiple of 2 going upto N. The loop then checks for the next empty set in the array, and whatever that
	value is, it adds it to each prime number set it is a multiple of. If a certain value has an empty array it is found
	that is a prime number, and therefore finding all prime numbers for each value.
	*/

	vector< set<unsigned> > prime_factors(N + 1);

	for (unsigned i = 2; i <= N; i++)
	{
		if (prime_factors[i].empty())
		{
			unsigned j = i + i;

			while (j <= N)
			{
				prime_factors[j].insert(i);

				j = j + i;
			}

			prime_factors[i].insert(i);
		}
	}

	/*-------------------------------------------------------------------------------------------------------------------
	The following loop finds the totient value for each value going upto N

	This is achieved by iterating through each value upto N, and using Euler's Totient formula. Each value's prime
	factors recorded from the previous loop are plugged into the equation, and then the totient value is saved in
	an array. The nested for loop iterates through each of value i's prime factors and converts them to a double type
	in order to complete part of Euler's Totient formula. 
	*/

	set<unsigned>::iterator it;
	unsigned value = 1;
	double itD;
	double valueD = 1;
	double noD;

	for (unsigned i = 1; i <= N; i++)
	{
		for (it = prime_factors[i].begin(); it != prime_factors[i].end(); ++it)
		{
			itD = (double)*it;

			valueD = valueD * (1.0 - (1.0 / itD));
		}
		
		noD = round(((double)i) * valueD);

		totient_values[i] = (unsigned int)noD;

		valueD = 1;
	}

	/*-------------------------------------------------------------------------------------------------------------------
	The following loop checks if two values are co-primes.
		
	This is achieved by using Eulers Totient formula for finding co-primes. The nested for loop checks two values from
	the 2D array is_coprime, and checks if their totient values multiplied are equal to the totient value of i and j. 
	If so, the i and j values are considered co-prime and the 2D array is_coprime will update the i and j position to 
	being true. Because the totient value for i*j may be out of range, the totient function is used to find its prime
	factors and return its totient value.
	*/

	for (unsigned i = 1; i <= N; i++)
	{
		for (unsigned j = i + 1; j <= N; j++)
		{
			if (totient(i * j) == (totient_values[i] * totient_values[j]))
			{
				is_coprime[i * max + j] = true;
			}

			unsigned z = totient(i * j);
		}
	}

	/*-------------------------------------------------------------------------------------------------------------------
	The following loop checks how many values in the array is_coprime are TRUE

	This is achieved by using a nested for loop to itterate over the full is_coprime 2D array, and when a boolean value
	is found to be TRUE the n_coprime value is increased by one.
	*/

	for (unsigned i = 0; i <= N; i++)
	{
		for (unsigned j = 0; j <= N; j++)
		{
			if (is_coprime[i * max + j] == true)
			{
				n_coprime++;
			}
		}
	}

	/*-------------------------------------------------------------------------------------------------------------------
	The following loop checks if two values are co-prime using the intersection method

	This is achieved by using a nested for loop to itterate over every value upto N, and check if the two values share
	any prime factors. If they do not share any prime factors the intersection between the two values prime factors
	will be zero, and the count value will increase by one signifying the two values are co-prime.

	This loop has been included to check the results between itself and the Eulers Totient method to find co-primes.
	*/

	unsigned count1 = 0;
	set<unsigned> intersection;

	for (unsigned i = 1; i <= N; i++)
	{
		for (unsigned j = i + 1; j <= N; j++)
		{
			set_intersection(prime_factors[i].begin(), prime_factors[i].end(),
				prime_factors[j].begin(), prime_factors[j].end(),
				inserter(intersection, intersection.begin()));

			if (intersection.empty())
			{
				count1++;
			}

			intersection.clear();
		}
	}

	/*-------------------------------------------------------------------------------------------------------------------
	The following lines print the number of co-primes found upto N, using the Euler's Totient method and the
	intersection method.
	*/

	cout << " The number of coprime numbers using the Euler's Totient method between 1 and " << N
		<< " is " << n_coprime + 1 << endl;

	cout << "\n The number of coprime numbers is checked using the intersection method between 1 and " << N
		<< " is " << count1 + 1 << endl;

	return 0;
}



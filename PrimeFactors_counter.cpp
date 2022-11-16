// PrimeFactors.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//Arin Bindra

#include <iostream>

#include <iostream> // cout
#include <algorithm> // set_intersection, sort
#include <set> // set
#include <iterator> // inserter
#include <vector>

using namespace std;

int main()
{

	unsigned max = 10;

	//--------------------------------------------------------------------------

	vector< set<unsigned> > prime_factors(max + 1);

	for (unsigned i = 2; i <= max; i++)
	{
		if (prime_factors[i].empty())
		{
			unsigned j = i + i;

			while (j <= max)
			{
				prime_factors[j].insert(i);

				j = j + i;
			}

			prime_factors[i].insert(i);
		}
	}


	//--------------------------------------------------------------------------
	// Finds prime factors using an intersection of 


	unsigned count1 = 0;
	set<unsigned> intersection;

	for (unsigned i = 1; i <= max; i++)
	{
		for (unsigned j = i + 1; j <= max; j++)
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

	cout << "There are: " << count1 << " coprimes, using the intersection method" << endl;

	//--------------------------------------------------------------------------
	
	/*
	If the intersection between the set of prime factors of a and the set of prime factors of b is 
	the empty set, then a and b are coprime.

	Therefore this is proved by contrapositive if the set of prime factors for a and b are different.

	a (no of prime factors) + b (no of prime factors) = size of union of a and b
	*/

	unsigned count2 = 0;
	set<unsigned> unionab;

	for (unsigned i = 1; i <= max; i++)
	{
		for (unsigned j = i + 1; j <= max; j++)
		{

			set_union(prime_factors[i].begin(), prime_factors[i].end(),
				prime_factors[j].begin(), prime_factors[j].end(),
				inserter(unionab, unionab.begin()));

			if ((prime_factors[i].size() + prime_factors[j].size()) == unionab.size())
			{
				count2++;
			}

			unionab.clear();
		}
	}

	cout << "There are: " << count2 << " coprimes, using the union method" << endl;


	return 0;
}

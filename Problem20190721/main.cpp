//This problem was asked by Amazon.
//
//Given a string, determine whether any permutation of it is a palindrome.
//
// For example, carrace should return true, since it can be rearranged to form racecar, which is a palindrome.
// daily should return false, since there's no rearrangement that can form a palindrome.


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Solution
{
private:
public:
	bool Solve(std::string text)
	{
		int cntTab[255];
		memset(cntTab, 0, sizeof(cntTab));

		//palindrom da sie utworzyc jeœi wszystkie pary tych samych znaków siê znios¹ wzajemnie
		//dla nieparzystych musi istniec jeden nie zniesionyznak
		for (auto c : text)
		{			
			cntTab[(int)c] ^= 1; 
		}
		int suma = 0;
		for (auto i : cntTab)
		{
			suma += i;
		}
		return text.length() % 2 == 0
			? suma == 0
			: suma == 1;		
	}
};

int main()
{
	// create treee from leafs to root
	
	Solution s;

	std::string tests[] =
	{
		"carrace",//true
		"daily", //false
		"annaalalkajak", //true		
	};

	for (auto t : tests)
	{
		printf("%s: %i\n", t.c_str(), s.Solve(t));
	}
	return 0;
}

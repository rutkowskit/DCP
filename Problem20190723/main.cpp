//This problem was asked by Google.
//
//Given a string, return the first recurring character in it, or null if there is no recurring character.
//
//For example, given the string "acbbac", return "b".Given the string "abcdef", return null.

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Solution
{
private:
public:
	std::string Solve(std::string text)
	{
		int cntTab[255];
		memset(cntTab, 0, sizeof(cntTab));

		//palindrom da sie utworzyc jeœi wszystkie pary tych samych znaków siê znios¹ wzajemnie
		//dla nieparzystych musi istniec jeden nie zniesionyznak
		for (auto c : text)
		{
			cntTab[(int)c]++;
			if (cntTab[(int)c] > 1)
				return std::string(1, c);
		}		
		return std::string();
	}
};

int main()
{
	// create treee from leafs to root

	Solution s;

	std::string tests[] =
	{
		"acbbac",//b
		"abcdef", //null
	};

	for (auto t : tests)
	{
		auto result = s.Solve(t);		
		printf("%s: %s\n", t.c_str(), result.empty() ? "<NULL>" : result.c_str());
	}
	return 0;
}

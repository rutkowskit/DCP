//Good morning!Here's your coding interview problem for today.
//
//This problem was asked by Stripe.
//
//Given an integer n, return the length of the longest consecutive run of 1s in its binary representation.
//
//For example, given 156, you should return 3.

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

typedef std::vector<std::pair<int, int>> TEST;

static int Solve(int number)
{
	int result = 0;
	int consec = 0;
	int bitNum = 1;
	int cnt = 0;
	while (number >= bitNum)
	{
		if ((number & bitNum) > 0)
		{
			consec++;
		}
		else
		{
			if (consec > result)
			{
				result = consec;
			}			
			consec = 0;
		}
		bitNum = 1 << ++cnt;
	}
	return result > consec ? result : consec;		
}


int main()
{
	TEST tests =
	{
		{156, 3 },
		{255, 8},
		{1, 1},
		{2, 1},
		{3, 2},
		{699050, 1}
	};

	for (auto t : tests)
	{
		auto result = Solve(t.first);
		std::cout << "Roman: " << t.first << "=" << result << ", expected: " << t.second
			<< " (" << (result == t.second ? "OK" : "ERROR") << ")\n";
	}
	return 0;
}

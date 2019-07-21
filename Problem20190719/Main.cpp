//Good morning!Here's your coding interview problem for today.
//This problem was asked by MongoDB.
//Given a list of elements, find the majority element, which appears more than half the time(> floor(len(lst) / 2.0)).
//You can assume that such element exists.
//
//For example, given[1, 2, 1, 1, 3, 4, 0], return 1.

#include <iostream>
#include <vector>
#include <algorithm>

typedef std::vector<int> vi;


class Solution
{
private:
public:
	int Solve(vi data)
	{
		//boyer-moore
		int sp = 0;
		int sValue = 0;
		
		for (auto i : data)
		{
			if (sp == 0)
			{
				sp++;
				sValue = i;
			}
			else sp += sValue != i ? -1 : 1;
		}		
		if (sp <= 0) return -1;		
		auto cnt = 0;
		for (auto i : data)
		{
			if (sValue != i) continue;			
			cnt++;
		}
		return cnt > data.size() / 2 ? sValue : -1;
	}
};

int main()
{
	// create treee from leafs to root
	vi data = { 1, 2, 1, 1, 3, 4, 1 }; //exempla data array is not correnct, because 3 number 1 is not a leader in 7 element set

	Solution s;

	auto result = s.Solve(data);

	printf("%d", result);

	return 0;
}

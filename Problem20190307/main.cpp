//This problem was asked by Snapchat.
//
//Given an array of time intervals(start, end) for classroom lectures(possibly overlapping), find the minimum number of rooms required.
//
//For example, given[(30, 75), (0, 50), (60, 150)], you should return 2.

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <math.h>

typedef std::vector<int> vi;
typedef std::pair<int, int> pi;
typedef std::vector<pi> vpi;

class Solution
{
private:
	inline bool OrderFunc(pi first, pi second) 
	{ 
		return (first.first < second.first); 
	}
public:
	int Solve(vpi& intervals)
	{		
		vpi se;
		se.reserve(2 * intervals.size());

		for (auto i : intervals)
		{
			se.push_back(pi(i.first, 0));
			se.push_back(pi(i.second, 1));
		}
		std::sort(se.begin(), se.end());
		
		int result = 0;
		int curState = 0;
		for (auto i : se)
		{
			if (i.second == 0) curState++;
			else curState--;
			if (curState > result) result = curState;			
		}
		return result;
	}
};

int main()
{	

	//vpi intervals = { pi(30,75),pi(0,50),pi(60,150) };	//2
	//vpi intervals = { pi(30,75),pi(75,95),pi(96,150) }; //2
	//vpi intervals = { pi(30,75),pi(76,95),pi(96,150) }; //1
	vpi intervals; //0

	Solution s;
	auto result = s.Solve(intervals);
	printf("%d", result);

	return 0;
}


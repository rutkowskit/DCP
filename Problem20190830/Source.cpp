//This problem was asked by Amazon.
//
//Given an array and a number k that's smaller than the length of the array, rotate the array to the right k elements in-place.

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

template<class T>
class Solution
{
private:
public:
	std::vector<T>& Solve(std::vector<T> &data, int step)
	{
		auto mod = data.size();		
		step = step % mod;
		if (step == 0) return data;
		
		for (int s = 0; s < step; s++)
		{
			int curPos = s;
			while ((curPos = (curPos + step) % mod)>s)
			{				
				std::swap(data[s], data[curPos]);
			}
			if (curPos < s) break;
		}
		return data;
	}
};


template <class T> inline void PrintVector(std::string title, std::vector<T> &result)
{
	std::cout << title <<" ";
	int cnt = 0;
	for (auto e : result)
	{
		if (cnt++ > 0) std::cout << ",";
		std::cout << e;
	}
}

template <class T> inline bool Assert(std::vector<T> &result, std::vector<T> &expected)
{
	if (result.size() != expected.size()) return false;
	for (auto i = 0; i < result.size(); i++)
	{
		if (result[i] != expected[i]) 
			return false;
	}
	return true;
}

int main()
{
	// create treee from leafs to root

	Solution<int> s;
		
	std::vector<int> testCases[] = 
	{ 
		{ std::vector<int>{ 6, 1, 2, 3, 4, 5 }},
		{ std::vector<int>{ 5, 6, 1, 2, 3, 4 }},
		{ std::vector<int>{ 4, 5, 6, 1, 2, 3 }},
		{ std::vector<int>{ 3, 4, 5, 6, 1, 2 }},
		{ std::vector<int>{ 2, 3, 4, 5, 6, 1 }},
		{ std::vector<int>{ 1, 2, 3, 4, 5, 6 }},
		{ std::vector<int>{ 6, 1, 2, 3, 4, 5 }}
	};
	int cnt = 1;
	for (auto i : testCases)
	{
		auto inData = std::vector<int>{ 1, 2, 3, 4, 5, 6 };
		auto result = Assert(s.Solve(inData, cnt), i);
		PrintVector("Expected:", i);		
		PrintVector(", Actual:", inData);		
		printf(",Step: %d: %s \n", cnt++, result ? "OK" : "Not OK");		
	}

	return 0;
}

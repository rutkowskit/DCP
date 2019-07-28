//This problem was asked by Google.
//
//You are given an array of length n + 1 whose elements belong to the set{ 1, 2, ..., n }.By the pigeonhole principle, there must be a duplicate.Find it in linear time and space.


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Solution
{
private:
public:
	int Solve(std::vector<int> data)
	{		
		auto j = data[0];			
		data[0] = -1; // number on idx 0 should be empty because numbers are from <1,n>

		while(1) //we assume that the data contains correct data, so additional checkings are ommited 
		{
			auto tmp = data[j]; //remember current value before replace with correct value
			if (tmp == j) return j; //if element on posisiotn j has value j, then we found duplicate :)
			data[j] = j;
			j = tmp;
		}		
		return -1;
	}
};

int main()
{
	// create treee from leafs to root

	Solution s;
	   
	auto result = s.Solve({4,2,1,3,2});
	printf("%d\n",result);
	
	return 0;
}

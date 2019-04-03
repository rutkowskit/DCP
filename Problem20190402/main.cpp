//This problem was asked by Facebook.
//Given a array of numbers representing the stock prices of a company in chronological order, write a function that calculates the maximum profit you could have made from buying and selling that stock once.You must buy before you can sell it.
//For example, given[9, 11, 8, 5, 7, 10], you should return 5, since you could buy the stock at 5 dollars and sell it at 10 dollars.
//Rutkowski: modified Kadane's algoritym

#include <iostream>
#include <vector>
#include <algorithm>

typedef std::vector<int> vi;

class Solution
{
private:	
public:
	int Solve(vi& data)
	{
		if (data.size() < 2) return 0;

		int maxProfit=0;		
		int max_ending = data[0];

		for (int i = 1; i < data.size(); i++)
		{
			int profit = data[i] - max_ending;
			if (profit <= 0) max_ending = data[i];			
			if (profit > maxProfit) maxProfit = profit;
		}
		
		return maxProfit;
	}
};

int main()
{

	vi prices = { 9, 11, 8, 5, 7, 10 };
	//vpi intervals = { pi(30,75),pi(75,95),pi(96,150) }; //2
	//vpi intervals = { pi(30,75),pi(76,95),pi(96,150) }; //1
	
	Solution s;
	auto result = s.Solve(prices);
	printf("%d", result);

	return 0;
}


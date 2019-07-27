//This problem was asked by Facebook.
//Given a 32 - bit integer, return the number with its bits reversed.
//For example, given the binary number 1111 0000 1111 0000 1111 0000 1111 0000, return 0000 1111 0000 1111 0000 1111 0000 1111.


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdint.h>

class Solution
{
private:
public:
	std::int32_t Solve(std::int32_t number)
	{
		std::int32_t result = 0;

		for (int i = 0; i < 32; i++)
		{
			auto flag = (1 << i);
			auto b = number & flag; //check if bit on position i is set
			if (!b) result |= flag; //set bit in result to 1 if bit on position i in number is 0
		}
		return result;
	}
	//converting helpers - just for fun
	static std::string IntToString(std::int32_t number)
	{
		char result[33];
		int cnt = 0;
		for (int i = 31; i >=0; i--)
		{
			result[cnt++] = (number & (1 << i)) != 0 ? '1' : '0';
		}
		result[cnt] = '\0';
		return std::string(result);
	}
	static std::int32_t StringToInt(std::string number)
	{
		std::int32_t result = 0;		
				
		int cnt = 0;

		for (auto it = number.rbegin(); it != number.rend(); ++it)
		{
			auto c = *it;
			if (c != '1' && c != '0') continue;
			if (c == '1') result |= (1 << cnt);
			cnt++;
		}		
		return result;
	}
};

int main()
{
	// create treee from leafs to root

	Solution s;

	std::string tests[] =
	{
		"11110000111100001111000011110000",//b		
		"10101010101",//b		
	};	
	
	for (auto txt : tests)
	{
		auto test = s.StringToInt(txt);
		auto result = s.Solve(test);

		std::cout << txt << "\n";
		std::cout << s.IntToString(result) <<"\n";
	}
	
	return 0;
}

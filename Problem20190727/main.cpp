//This problem was asked by Jane Street.
//
//Given an arithmetic expression in Reverse Polish Notation, write a program to evaluate it.
//
//The expression is given as a list of numbers and operands.For example : [5, 3, '+'] should return 5 + 3 = 8.
//
//For example, [15, 7, 1, 1, '+', '-', '/', 3, '*', 2, 1, 1, '+', '+', '-'] should return 5, since it is equivalent to((15 / (7 - (1 + 1))) * 3) - (2 + (1 + 1)) = 5.
//
//You can assume the given expression is always valid.


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdint.h>
#include <stack>

class Solution
{
private:
	inline static bool IsNumChar(char c)
	{
		return (c >= '0' && c <= '9');
	}
	inline static int ReadNum(std::string::iterator &it)
	{

		std::stack<int> nums;
		while (IsNumChar(*it))
		{
			nums.push((*it - 0x30));			
			it++;
		}
		int result = 0;
		int p = 1;
		while (nums.size() > 0)
		{
			auto x = nums.top() * p;
			result += x;
			nums.pop();			
			p *= 10;			
		}
		return result;
	}
	inline static char ReadOperand(std::string::iterator &it)
	{
		
		if ((*it) != '\'') return '\0';
		it++;
		char result = *it;
		it+=2;
		return result;		
	}
	inline static int Evaluate(int p1, int p2, char op)
	{
		switch (op)
		{
			case '+': return p1 + p2;			
			case '-': return p1 - p2;			
			case '*': return p1 * p2;			
			case '/': return p1 / p2;			
			default: throw std::exception("invalid operand");
		}
	}
public:
	int Solve(std::string exp)
	{
		std::stack<int> stack;
		
		for (auto it=exp.begin();it!=exp.end();++it)
		{			
			if (IsNumChar(*it))
			{
				stack.push(ReadNum(it));
			}
			else if ((*it) == '\'')
			{
				auto op = ReadOperand(it);
				auto p2 = stack.top();
				stack.pop();
				auto p1 = stack.top();
				stack.pop();	
				stack.push(Evaluate(p1, p2, op));				
			}
		}
		if(stack.size()!=1)
			throw std::exception("invalid expression");
		return stack.top();
	}	
};

int main()
{
	// create treee from leafs to root

	Solution s;

	std::string tests[] =
	{
		"[15, 7, 1, 1, '+', '-', '/', 3, '*', 2, 1, 1, '+', '+', '-']",//b		
		"[5, 3, '+']",//b		
		"[15555, 33, '*',8323,'+']",//b		
	};
		
	for (auto txt : tests)
	{		
		auto result = s.Solve(txt);
		std::cout << txt <<"=" << result << "\n";		
	}
	std::cout << "Done.";
	auto c = getchar();
	return 0;
}

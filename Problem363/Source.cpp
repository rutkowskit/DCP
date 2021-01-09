//Good morning!Here's your coding interview problem for today.
//
//This problem was asked by Squarespace.
//
//Write a function, add_subtract, which alternately addsand subtracts curried arguments.Here are some sample operations :
//
//add_subtract(7) -> 7
//
//add_subtract(1)(2)(3) -> 1 + 2 - 3 -> 0
//
//add_subtract(-5)(10)(3)(9) -> - 5 + 10 - 3 + 9 -> 11

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

class add_subtract
{
private:
	int _sum;
	int _sign;
public:
	add_subtract(int startValue, int sign=1)
	{
		_sum = startValue;
		_sign = sign;
	}
	add_subtract operator()(const int value)
	{
		return add_subtract(_sum + value*_sign, _sign*-1); //add value with current sign, create new state and change operation sign
	}
	// cast to int operator - final result cast
	operator const int() 
	{
		return _sum;
	}
};

int main()
{
	int result = add_subtract(7);
	_ASSERT(result == 7);
	result = add_subtract(1)(2)(3);
	_ASSERT(result == 0);
	result = add_subtract(-5)(10)(3)(9);
	_ASSERT(result == 11);		
	return 0;
}

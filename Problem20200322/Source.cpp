// This problem was asked by Twitter.
// A strobogrammatic number is a positive number that appears the same after being rotated 180 degrees.For example, 16891 is strobogrammatic.
// Create a program that finds all strobogrammatic numbers with N digits.

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class StroboNumber
{
private:
	#define MAX_IDX 5
	const unsigned char _digits[MAX_IDX]={ '0','1','6','8','9' };
	std::vector<int> _leftSideIdx;
	int _left, _right, _length;		
public :
	StroboNumber(int length)
	{
		auto half = (int)(length / 2);
		auto rest = length - half;
		_length = length;
		_left = half > rest ? half : rest;
		_right = length - _left;
		_leftSideIdx.resize(_left,0);		
		_leftSideIdx[0] = _length > 1 ? 1 : 0; //starting number
	}
	inline bool Next()
	{		
		bool carry = false;
		for (int i = 0; i < _left; i++)
		{
			carry = (_leftSideIdx[i] + 1) == MAX_IDX;
			_leftSideIdx[i] = carry
				? (_length > 1 ? 1 : 0)
				: _leftSideIdx[i] + 1;
			if (i >= _right) //middle char cannot be 6 or 9
			{
				auto curChar = _digits[_leftSideIdx[i]];
				if (curChar == '6')
					_leftSideIdx[i] = _leftSideIdx[i] + 1;
				else if (curChar == '9')
					return false;
			}
			if (!carry)
				break;
		}
		return !carry; //if carry not release, then there is no next number
	}
	inline void Print()
	{
		for (auto c : _leftSideIdx)
		{
			printf("%c", _digits[c]);
		}
		for (int i = _right-1; i >= 0; --i)
		{
			auto c = _digits[_leftSideIdx[i]];
			if (c == '6') c = '9';
			else if (c == '9') c = '6';
			printf("%c", c);
		}
		printf("\n");
	}
};

int main()
{
	// create treee from leafs to root
	//for (auto i = 1; i < 50; i++)
	auto i = 7;
	{
		int cnt = 0;
		StroboNumber num(i);
		do
		{
			cnt++;
			printf("%d\t", cnt++);
			num.Print();
		} while (num.Next());
		printf("For N=%d, %d strobo numbers\n", i, cnt);
	}

	return 0;
}

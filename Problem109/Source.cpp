//This problem was asked by Cisco.
//Given an unsigned 8 - bit integer, swap its evenand odd bits.The 1st and 2nd bit should be swapped, the 3rd and 4th bit should be swapped, and so on.
//For example, 10101010 should be 01010101. 11100010 should be 11010001.
//Bonus: Can you do this in one line ?

#include <iostream>
#include <map>
#include <vector>
#include <string>

typedef unsigned char Byte;
typedef std::vector<std::pair<Byte, Byte>> TestSet;

void PrintBinary(Byte number, int bit)
{
	if (bit < 7) PrintBinary(number, bit + 1);
	printf("%d", number & 1 << bit ? 1 : 0);
}

class Solution
{
private:
	int _sum;
	int _sign;
public:
	Byte Solve(Byte number)
	{
		// one liner solution - logic sum of masked shifted numbers
		return ((number << 1) & 0b10101010) | ((number >> 1) & 0b01010101);

		// iterative solution
		/*byte result = 0;
		for (int i = 0; i < 4; i++)
		{
			result |= (((toMash & 1 << i * 2+1)>>1 | (toMash & 1 << i * 2)<<1));			
		}
		return result;*/
	}
};

int main()
{
	Solution solver;
	TestSet tests =
	{
		{0b10101010, 0b01010101},
		{0b10, 0b01},
		{0b11, 0b11},
		{0,0}
	};
		
	for (auto t : tests)
	{
		Byte result = solver.Solve(t.first);
		PrintBinary(t.first, 0);
		printf(" ");
		PrintBinary(t.second, 0);
		printf(" ");
		PrintBinary(result, 0);
		printf(" ");
		printf("%s\n", result == t.second ? "OK" : "ERROR");
	}	
	return 0;
}

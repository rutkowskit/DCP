//Good morning!Here's your coding interview problem for today.
//
//This problem was asked by Facebook.
//
//Given a number in Roman numeral format, convert it to decimal.
//
//The values of Roman numerals are as follows :
//
//{
//	'M': 1000,
//		'D' : 500,
//		'C' : 100,
//		'L' : 50,
//		'X' : 10,
//		'V' : 5,
//		'I' : 1
//}
//
//In addition, note that the Roman numeral system uses subtractive notation for numbers such as IVand XL.
//
//For the input XIV, for instance, you should return 14.


#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>


typedef std::vector<std::pair<std::string, int>> VPSI;

std::map<char, int> _digitMap = { {'I',1 }, {'V',5 }, {'X',10 }, {'L',50 }, {'C',100 }, {'D',500 }, {'M',1000 } };

class RomanNumber
{
private:			
	std::string _number;
public:
	RomanNumber(std::string number)
	{
		_number = number;
	}
	int AsInteger()
	{		
		int result = 0;		
		int prev = 0;
		for (auto i = 0; i < _number.length(); i++)
		{			
			int digit = _digitMap[_number[i]];
			if (prev == 0)
			{
				prev = digit;
				continue;
			}
			// apply substraction if previous digit value is lower than current. Then reset "block"
			if (digit > prev) 
			{
				result += (digit - prev);
				prev = 0;
			}
			else
			{
				result += prev;
				prev = digit;
			}
		}
		if (prev > 0) 
			result += prev;
		return result;
	}
};

int main()
{
	VPSI tests = 
	{ 
		{"I", 1 },
		{"IV", 4 },
		{"IX", 9 },
		{"IXI", 10 },
		{"DCCLXXXIX", 789 },
		{"MMCDXXI", 2421}, 
		{"MDCCLXXVI", 1776},
		{"MCMLIV", 1954},
		{"MMXIV", 2014},
		{"MMXX", 2020},
		{"MIX", 1009},
		{"MLXVI", 1066}
	};
	
	for (auto t : tests)
	{
		auto roman = RomanNumber(t.first);
		auto num = roman.AsInteger();
		std::cout << "Roman: " << t.first << "=" << num << ", expected: " << t.second 
				  << " (" << (num == t.second ? "OK" : "ERROR") << ")\n"; 
	}	
	return 0;
}

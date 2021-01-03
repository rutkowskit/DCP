//Good morning!Here's your coding interview problem for today.
//
//This problem was asked by Amazon.
//
//Run - length encoding is a fast and simple method of encoding strings.The basic idea is to represent repeated successive characters as a single count and character.For example, the string "AAAABBBCCDAA" would be encoded as "4A3B2C1D2A".
//
//Implement run - length encoding and decoding.You can assume the string to be encoded have no digits and consists solely of alphabetic characters.You can assume the string to be decoded is valid.

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

typedef std::vector<std::pair<std::string, std::string>> VIS;

class Solution
{
private:
	inline int CountChars(std::string &text, int startIdx, char c)
	{
		int result = 0;
		for (int i = startIdx; i < text.length(); ++i)
		{
			if (text[i] == c) result++;
			else break;
		}
		return result;
	}
public:	
	std::string Encode(std::string toEncode)
	{
		int idx = 0;
		auto len = toEncode.length();
		std::string result = "";
		while (idx<len)
		{
			char c = toEncode[idx];
			int cnt = CountChars(toEncode, idx, c);
			result = result + std::to_string(cnt);
			result.push_back(c);
			idx += cnt;
		}	
		return result;
	}	
};

int main()
{
	VIS tests =
	{
		{"AAAABBBCCDAA", "4A3B2C1D2A" },
		{"ABCDEFG", "1A1B1C1D1E1F1G" },
		{"CCABBF", "2C1A2B1F" }

	};
	Solution solver;

	for (auto t : tests)
	{
		auto encoded = solver.Encode(t.first);		
		std::cout << t.first.c_str() << "=" << t.second.c_str() << "==" << encoded << "? " << (encoded==t.second ? "[YES]" : "[NO]") <<"\n";
	}
	return 0;
}

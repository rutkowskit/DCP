//This problem was asked by Square.
//
//Given a list of words, return the shortest unique prefix of each word.For example, given the list :
//
//dog
//cat
//apple
//apricot
//fish
//
//Return the list :
//
//d
//c
//app
//apr
//f


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>


class MyString
{
private:
	std::string _text;
	int _prefixLen;
	int _len;
	MyString() {}	
	MyString(MyString& str) {}
	std::vector<MyString*> _sameOnPosition;

public :
	MyString(std::string text)
	{
		_text = std::string(text);
		_prefixLen = 0;
		_len = _text.length();
	}	
	inline char GetChar(int position)
	{
		return position >= _len ? '\0' : _text[position];
	}
	inline void AddNextWithSamePrefix(MyString* str)
	{
		_sameOnPosition.push_back(str);
	}
	inline bool HasNextWithSamePrfix()
	{
		return _sameOnPosition.size() > 0;
	}
	inline std::vector<MyString*> GetAllSimilarPrefix()
	{
		std::vector<MyString*> result = _sameOnPosition;
		_sameOnPosition.clear(); //clear children with same prefix
		result.push_back(this);
		return result;
	}
	inline void SetPrefixLen(int prefixLen	)
	{
		_prefixLen = prefixLen >= _len ? _len : prefixLen;
	}
	inline std::string GetPrefix()
	{
		return _text.substr(0, _prefixLen);
	}

	inline std::string GetText()
	{
		return _text;
	}
	~MyString()
	{
		_sameOnPosition.clear();
	}
};

class Solution
{
public:
	inline void Solve(std::vector<MyString*> txtList, int position)
	{		
		std::map<char, MyString*> posLetter; 	

		for (auto s : txtList)
		{
			auto c = s->GetChar(position);
			if (c == '\0') continue;
			int idx = (int)c;
			s->SetPrefixLen(position + 1);
			if (!posLetter[idx])
			{
				posLetter[idx] = s;
			}
			else
			{
				posLetter[idx]->AddNextWithSamePrefix(s); //add next with same prefix (child) to first occurence
			}
		}
		for (auto s : posLetter)
		{			
			if (!s.second->HasNextWithSamePrfix()) 
				continue;
			Solve(s.second->GetAllSimilarPrefix(), position + 1); //process strings with same prefix
		}		
	}		
};

int main()
{
	// create treee from leafs to root

	Solution s;

	std::vector<MyString*> tests = 	
	{
		new MyString("dog"),
		new MyString("cat"),
		new MyString("apple"),
		new MyString("apricot"),
		new MyString("fish"),
		new MyString("fisher")
	};

	s.Solve(tests, 0);
	for (auto t : tests)
	{
		std::cout << t->GetText() <<", prefix: "<< t->GetPrefix() <<"\n";
		delete(t);
	}
	return 0;
}

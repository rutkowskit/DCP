//Good morning!Here's your coding interview problem for today.
//This problem was recently asked by Google.
//Given a list of numbers and a number k, return whether any two numbers from the list add up to k.
//For example, given[10, 15, 3, 7] and k of 17, return true since 10 + 7 is 17.
//Bonus: Can you do this in one pass ?
//
#include "pch.h"
#include <iostream>
#include <unordered_set>

typedef std::unordered_set<int> HashSet;

int main()
{
	int k=14;
	int arr[] = { 10,15,3,7 };

	HashSet h;
	bool result = false;
	for (int i : arr)
	{	
		auto lookFor = k - i;
		auto found=h.find(lookFor);
		if (found != h.end())
		{
			result = true;
			break;
		}
		h.insert(i); //remember this element
	}
	printf("%s", result ? "True" : "False");
	return 0;
}

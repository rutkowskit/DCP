//Good morning!Here's your coding interview problem for today.
//This problem was asked by Uber.
//Given an array of integers, return a new array such that each element at index i of the new array is the product of all the numbers in the original array except the one at i.
//For example, if our input was[1, 2, 3, 4, 5], the expected output would be[120, 60, 40, 30, 24].If our input was[3, 2, 1], the expected output would be[2, 3, 6].
//Follow - up: what if you can't use division?

//rutkowski: najbardziej trywialnym rozwiazaniem by³o by obliczenie iloczynu wszystkich wartœci i póŸniej podzieliæ ten wynik kolejno przez ka¿dy element tablicy tab.
//w za³o¿eniu ¿e nie mozemy stosowac dzielenia, wówczas mo¿na zastosowaæ tablicê prefikso-sufiksów zawieraj¹c¹ iloczyny od "przodu" i od "ty³u"
//poni¿ej rozwiazanie

#include "pch.h"
#include <iostream>
#include <vector>

typedef std::vector<int> vi;

class Solution
{
public:
	vi Solve(vi& tab)
	{
		vi result;
		vi pref;
		vi post;
		//neutralna "dummy" liczba dla uproszczenia
		pref.push_back(1);
		post.push_back(1);

		//wyznaczeniue tablicy prefiksów
		auto s = tab.size();
		for (auto i = 0; i < s; i++)
		{
			pref.push_back(pref[i] * tab[i]);
			post.push_back(post[i] * tab[s - i - 1]);
		}

		//wypisanie wyniku
		for (auto i = 1; i <= s; i++)
		{
			result.push_back(pref[i - 1] * post[s - i]);
		}
		return result;
	}
};

int main()
{
	vi tab = {3,2,1};	

	Solution s;
	vi result = s.Solve(tab);
	for (auto r : result)
	{
		printf("%d ", r);
	}
	return 0;
}


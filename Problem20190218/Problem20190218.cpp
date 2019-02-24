//Good morning!Here's your coding interview problem for today.
//This problem was asked by Stripe.
//Given an array of integers, find the first missing positive integer in linear time and constant space.In other words, find the lowest positive integer that does not exist in the array.The array can contain duplicates and negative numbers as well.
//For example, the input[3, 4, -1, 1] should give 2. The input[1, 2, 0] should give 3.
//You can modify the input array in - place.

//rutkowski: spodziewany wynik b�dzie na pewno mniejszy od rozmiaru tablicy. Je�li cokolwiek b�dzie wi�ksze lub mniejsze od liczby 
//elementow w tablicy, to mo�na to spokojnie wyzerowa� bo na pewno b�dzie nie b�dzie to szukana liczba
//wi�c wystarczy wyzerowac liczby spoza zakresu, liczby z zakresu od 1 do tab.size() ustawiamy w konkretnych indeksach
//w drugiej iteracji sprawdzamy pierwszy indeks, kt�ry ma warto�� 0 i to b�dzie rozwi�zanie

#include "pch.h"
#include <iostream>
#include <vector>

typedef std::vector<int> vi;

class Solution
{
public:
	inline int Solve(vi& tab)
	{	
		int s = tab.size();

		for (int i = 0; i < s; i++)
		{
			int val = tab[i];
			if (val - 1 == i || val == 0)
				continue; //ten element jest ju� na prawid�owej pozycji lub jest brakujacy

			tab[i] = 0; //zwalniamy niepasujacy element			
			while (val > 0 && tab[val - 1] != val && val <= s)
			{
				int backup = tab[val - 1];
				tab[val - 1] = val;
				val = backup;
				if (val > s)
					val = 0; //wychodzimy dopiero gdy pozbedziemy sie nieumiejscowionej wartosci
			}
		}//O(2n)
		for (int i = 0; i < s; i++)
		{
			if (tab[i] == 0) //na pozycji i jest brakujacy element wiec wynikiem jest i+1 (bo taka warto�� tu by� powinna)
				return i + 1;
		}//O(n) +O(2n) - czyli liniowa z�o�ono�� obliczeniowa i sta�a z�o�ono�� pami�ciowa, bo operacje s� na istniej�cym wektorze
		return 1; //tutaj nigdy nie powinni�my si� znale��. ale je�li b�dzie pusta tablica, to wynikiem b�dzie 1 zgodnie z przykladem
	}
};

int main()
{
	vi tab = { 5,8,2,1,3,9,7,4,2 };

	Solution s;
	auto result = s.Solve(tab);
	printf("%d\n",result);	
	return 0;
}


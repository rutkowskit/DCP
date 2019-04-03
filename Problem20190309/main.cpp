//This problem was asked by Google.
//You are given an M by N matrix consisting of booleans that represents a board.Each True boolean represents a wall.Each False boolean represents a tile you can walk on.
//Given this matrix, a start coordinate, and an end coordinate, return the minimum number of steps required to reach the end coordinate from the start.If there is no possible path, then return null.You can move up, left, down, and right.You cannot move through walls.You cannot wrap around the edges of the board.
//For example, given the following board :
//
//[[f, f, f, f],
//[t, t, f, t],
//[f, f, f, f],
//[f, f, f, f]]
//
//and start = (3, 0) (bottom left) and end = (0, 0) (top left), the minimum number of steps required to reach the end is 7, since we would need to go through(1, 2) because there is a wall everywhere else on the second row.

//TODO: dopracowaæ - to nie dzia³a jeszcze prawid³owo

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <math.h>
#include <bitset>
#include <limits>

typedef std::vector<int> vi;
typedef std::vector<vi> vvi;

typedef std::pair<int, int> pi;
typedef std::vector<bool> vb;
typedef std::vector<vb> vvb;


class Solution
{
private:	
	vvi _memo;
	vvb* _board;
	pi _end;
	int _widht;
	int _height;

public:
	Solution(vvb& board, pi& end)
	{
		_end = end;
		_board = &board;
		_height = (int)board.size();
		_widht = (int)board[0].size();
		_memo.resize(_height);

		for (int i = 0; i < _height; i++)
		{
			_memo[i].resize(_widht,-1);
		}
	}
	int Solve(pi start, int step)
	{		
		if (start.first < 0 || start.second < 0 || start.first>=_height || start.second>=_widht)
			return INT_MAX;
		if (start.first == _end.first && start.second == _end.second)
			return step;
		auto m = _memo[start.first][start.second];
		if (m >= 0)	
			return m==INT_MAX ? m: m+step;
				
		_memo[start.first][start.second] = INT_MAX; //mark as visited
		if ((*_board)[start.first][start.second]) //wall
		{			
			return INT_MAX;
		}

		int result = INT_MAX;
		auto tmp = Solve(pi(start.first - 1, start.second), step + 1); //left
		if (tmp < result) result = tmp;
		tmp = Solve(pi(start.first + 1, start.second), step + 1); //right
		if (tmp < result) result = tmp;			
		tmp = Solve(pi(start.first, start.second-1), step + 1); //top
		if (tmp < result) result = tmp;
		tmp = Solve(pi(start.first, start.second+1), step + 1); //bot
		if (tmp < result) result = tmp;
				
		_memo[start.first][start.second] = result; //memoize min path
		return result;
	}
};

int main()
{

	vvb board = 
	{
		{0,0,0,0},
		{1,1,0,1},
		{0,1,0,0},
		{0,0,1,0},
		{0,0,0,0},
		{0,0,0,1},
		{0,1,0,0},
	};
	pi start(0, 0);
	pi end(3,0);

	Solution s(board,end);

	auto result = s.Solve(start,0);
	if (result == INT_MAX)
		printf("NULL\n"); //no path
	else
		printf("%d\n", result); //path found
	return 0;
}


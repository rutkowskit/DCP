//This problem was asked by Google.
//
//Given two singly linked lists that intersect at some point, find the intersecting node.The lists are non - cyclical.
//
//For example, given A = 3 -> 7 -> 8 -> 10 and B = 99 -> 1 -> 8 -> 10, return the node with value 8.
//
//In this example, assume nodes with the same value are the exact same node objects.
//
//Do this in O(M + N) time(where M and N are the lengths of the lists) and constant space.

#include <iostream>
#include <vector>

typedef std::vector<int> vi;
typedef long long LL;


class OrderLog
{
private:
	OrderLog() {}
	int* _orders;
	int _size;
	int _count;
	inline int GetCurrentPosition()
	{
		return (_count % _size);
	}
public:

	OrderLog(int size)
	{
		_size = size;
		_orders = new int[size];
		_count = 0;
	}
	~OrderLog()
	{
		delete(_orders);
	}
	void Record(int orderId)
	{
		_orders[_count++%_size] = orderId;
	}

	vi GetLast(int count)
	{
		vi result;
		int lcount = count > _size ? _size : count;
		if (_count == 0) return result; //no log entries

		if (lcount >= _count) //requested more entries than there is in log - retur all
		{
			for (int i = 0; i < _count; i++)
				result.push_back(_orders[i]);
		}
		else
		{
			int pos = GetCurrentPosition();
			int from = pos - lcount;
			if (from < 0) from = _size + from;
			for (int i = 0; i < lcount; i++)
				result.push_back(_orders[from++%_size]);

		}
		return result;
	}
};


int main()
{
	OrderLog sut = OrderLog(150000);

	for (int i = 0; i < 200000; i++)
	{
		sut.Record(i);
	}

	auto result = sut.GetLast(14);
	for (auto x : result)
	{
		printf("%d,", x);
	}

	return 0;
}


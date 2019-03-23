//Good morning!Here's your coding interview problem for today.
//This problem was asked by Twitter.
//You run an e - commerce website and want to record the last N order ids in a log.Implement a data structure to accomplish this, with the following API :
//record(order_id) : adds the order_id to the log
//get_last(i) : gets the ith last element from the log.i is guaranteed to be smaller than or equal to N.
//You should be as efficient with time and space as possible.


#include <iostream>
#include <vector>
#include <math.h>
typedef std::vector<int> vi;
typedef long long LL;


class OrderLog
{
private:
	OrderLog()	{}
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
			for (int i =0; i < lcount; i++)
				result.push_back(_orders[from++%_size]);

		}
		return result;		
	}	
};


int main()
{
	OrderLog sut = OrderLog(150000);

	for (int i = 0; i <200000; i++)
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


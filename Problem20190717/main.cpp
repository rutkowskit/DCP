//This problem was asked by Amazon.
//Implement a stack API using only a heap.A stack implements the following methods :
//
//push(item), which adds an element to the stack
//pop(), which removes and returns the most recently added element(or throws an error if there is nothing on the stack)
//
//Recall that a heap has the following operations :
//push(item), which adds a new key to the heap
//pop(), which removes and returns the max value of the heap


#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

typedef std::vector<int> vi;


template <class T> class HeapStack
{
private:
	int _count;
	std::map<int, int> _heap; //map works "like" heap - keys are ordered

	//std::pair<int,T> 
public:
	HeapStack()
	{
		_count = 0;
	}
	void Push(T item)
	{
		_heap[_count++] = item;
	}

	T Pop()
	{
		if (_count == 0)
			throw std::exception("Stack is empty");
		auto lastEl = _heap.rbegin();
		auto result = lastEl->second;
		_heap.erase(lastEl->first);
		_count--;
		return result;
	}
};


int main()
{
	HeapStack<int> stack;

	stack.Push(10);
	stack.Push(3);
	stack.Push(5);
	stack.Push(2);
	stack.Push(3);
	stack.Push(4);
	stack.Push(645);

	try
	{
		for (int i = 0; i < 10000; i++)
		{
			int x = stack.Pop();
			printf("SP: %d, Item: %d\n", i, x);
		}
	}
	catch (std::exception &ex)
	{
		printf("Exception thrown: %s\n", ex.what());
	}
	return 0;
}

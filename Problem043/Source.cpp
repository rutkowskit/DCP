//Good morning!Here's your coding interview problem for today.
//
//This problem was asked by Amazon.
//
//Implement a stack that has the following methods :
//
//push(val), which pushes an element onto the stack
//pop(), which pops offand returns the topmost element of the stack.If there are no elements in the stack, then it should throw an error or return null.
//max(), which returns the maximum value in the stack currently.If there are no elements in the stack, then it should throw an error or return null.
//
//Each method should run in constant time.

#include <iostream>
#include <map>
#include <vector>
#include <string>


template<class T> struct StackElement
{
public:
	StackElement(T value)
	{
		Value = value;
		Prev = NULL;
		MaxSoFar = value;
	}
	T Value;
	T MaxSoFar;
	StackElement* Prev;	
};

class IntStack
{
private:		
	StackElement<int>* _top;	
	int _max;
public:	
	IntStack()
	{
		_top = NULL;		
		_max = INT_MIN;
	}
	void Push(int val)
	{
		auto newElement = new StackElement<int>(val);
		newElement->Prev = _top;		
		if(!_top)
		{
			_max = val;
		}
		else if(_top->MaxSoFar<val)
		{
			_max = val;
		}
		_top = newElement;
		_top->MaxSoFar = _max;
	}	
	int Pop()
	{
		if(_top==NULL)
			throw std::exception("stack is empty");
		auto result = _top->Value;
		auto toPop = _top;
		_top = _top->Prev;
		delete(toPop);		
		return result;
	}
	int Max()
	{
		if (_top==NULL)
			throw std::exception("stack is empty");
		return _top->MaxSoFar;
	}
};


int main()
{
	IntStack stack;
	std::vector<int> tests = { 5,10,3,300,4,12,3001,10,100 };
	
	for (auto t : tests)
	{
		stack.Push(t);
	}
	for (int i = 0; i < tests.size(); i++)
	{
		printf("Max: %d ", stack.Max());
		printf("Value: %d \n", stack.Pop());
	}
	return 0;
}

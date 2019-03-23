//Good morning!Here's your coding interview problem for today.
//This problem was asked by Google.
//An XOR linked list is a more memory efficient doubly linked list.Instead of each node holding next and prev fields, it holds a field named both, 
//which is an XOR of the next node and the previous node.Implement an XOR linked list; it has an add(element) which 
//adds the element to the end, and a get(index) which returns the node at index.
//If using a language that has no pointers(such as Python), you can assume you have access to get_pointer and dereference_pointer 
//functions that converts between nodes and memory addresses.

#include <iostream>
#include <vector>

typedef std::vector<int> vi;
typedef long long LL;

template <class EType> class Node
{
private:
	EType _value;
	LL _both;
public:
	Node(EType value)
	{
		_both = 0;
		_value = value;
	}
	EType GetValue()
	{
		return _value;
	}
	LL GetLink()
	{
		return _both;
	}
	Node<EType>* GetNext(Node<EType> *prev)
	{
		return !prev
			? (Node<EType>*)_both
			: (Node<EType>*)(_both ^ (LL)prev);
	}
	void LinkTo(Node<EType>* element)
	{
		if (!element) return;
		if (_both == 0)
		{
			_both = (LL)element;
		}
		else
		{
			_both ^= (LL)element;
		}
	}
	void UnlinkFrom(Node<EType>* element)
	{
		if (!element) return;
		_both ^= (LL)element;
	}
};


template <class EType> class XorList
{
private:
	Node<EType> *_lastElement;
	Node<EType> *_firstElement;
	int _count;

	std::pair<Node<EType>*, Node<EType>*> GetAt(int index)
	{
		if (index >= _count)
			throw std::out_of_range("Index out of range");

		int numOfSteps = index;
		Node<EType> *prevEl = _firstElement;

		//jeœli wskazany indeks jest bli¿ej koñca to lecimy travers od ostatniego elementu - wtedy z³o¿onoœæ czasowa wyszukiwania O(n/2)
		if ((_count - index) < index)
		{
			prevEl = _lastElement;
			numOfSteps = (_count - 1) - index;
		}
		Node<EType> *nextEl = (Node<EType>*)prevEl->GetLink();
		while (numOfSteps--)
		{
			auto newNext = nextEl->GetNext(prevEl);
			prevEl = nextEl;
			nextEl = newNext;
		}
		auto result = std::pair<Node<EType>*, Node<EType>*>(prevEl, nextEl);
		return result;
	}

public:
	XorList()
	{
		_count = 0;
		_lastElement = NULL;
		_firstElement = NULL;
	}
	void Add(EType element)
	{
		Node<EType> *toAdd = new Node<EType>(element);
		if (NULL == _firstElement)
		{
			_firstElement = toAdd;
			_lastElement = _firstElement;
		}
		else
		{
			_lastElement->LinkTo(toAdd);
			toAdd->LinkTo(_lastElement);
			_lastElement = toAdd;
		}
		_count++;
	}
	int Size()
	{
		return _count;
	}

	EType Get(int index)
	{
		auto result = GetAt(index);
		return result.first->GetValue();
	}
	//to dla zabawy - poza treœci¹ zadania
	void RemoveAt(int index)
	{
		auto result = GetAt(index);

		Node<EType>* toRemove = result.first;
		Node<EType>* next = result.second;
		Node<EType>* prev = NULL == next
			? (Node<EType>*) toRemove->GetLink()
			: toRemove->GetNext(next);

		if (next)
		{
			next->UnlinkFrom(toRemove);
			next->LinkTo(prev);
		}

		if (prev)
		{
			prev->UnlinkFrom(toRemove);
			prev->LinkTo(next);
		}
		if (toRemove == _firstElement)
			_firstElement = next ? next : prev;

		if (toRemove == _lastElement)
			_lastElement = next ? next : prev;

		delete(toRemove);
		_count--;
	}
	//destruktor dla zabawy i dla porz¹dku
	~XorList()
	{
		if (!_firstElement) return;

		Node<EType> *prevEl = _firstElement;
		Node<EType> *nextEl = (Node<EType>*)prevEl->GetLink();
		while (nextEl)
		{
			auto newNext = nextEl->GetNext(prevEl);
			delete(prevEl);
			prevEl = nextEl;
			nextEl = newNext;
		}
		if (prevEl)
		{
			delete(prevEl);
			_firstElement = NULL;
			_lastElement = NULL;
		}
	}
};


int main()
{
	vi testValues = { 1,6,100,12,13 };

	XorList<int> linkedList;
	for (int i : testValues)
	{
		linkedList.Add(i);
	}
	//dla testu sprawdzamy czy wszystkie wartoœci siê zgadzaj¹ ka ka¿dej pozycji
	for (int i = 0; i < testValues.size(); i++)
	{
		auto expected = testValues[i];
		auto val = linkedList.Get(i);
		_ASSERTE(expected == val);
	}

	//test dodatkowy dla ma³ej listy
	XorList<int> linkedList2;
	linkedList2.Add(1);
	linkedList2.Add(2);

	linkedList2.RemoveAt(1);
	linkedList2.RemoveAt(0);

	for (int i = 0; i < linkedList2.Size(); i++)
	{
		printf("%d,", linkedList2.Get(i));
	}
}


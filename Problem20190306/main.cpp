//This problem was asked by Google.
//Given two singly linked lists that intersect at some point, find the intersecting node.The lists are non - cyclical.
//For example, given A = 3 -> 7 -> 8 -> 10 and B = 99 -> 1 -> 8 -> 10, return the node with value 8.
//In this example, assume nodes with the same value are the exact same node objects.
//Do this in O(M + N) time(where M and N are the lengths of the lists) and constant space.

#include <iostream>
#include <vector>
#include <set>

typedef std::vector<int> vi;


template<class T> class Node
{
private:
	T _element;
	Node() {}
	Node<T>* _next;
public:
	Node(T element)
	{
		_element = element;
	}	
	void SetNext(Node<T>* next)
	{
		_next = next;
	}
	Node<T>* GetNext()
	{
		return _next;
	}
	T GetValue()
	{
		return _element;
	}
};


template<class T> class LinkedList
{
private:
	Node<T>* _root;
	Node<T>* _last;
	int _count;
public:

	LinkedList(T elements[]):LinkedList()
	{
		for (auto t : elements) Add(new Node<T>(t));		
	}

	LinkedList()
	{
		_count = 0;
		_root = NULL;
		_last = NULL;
	}

	void Add(Node<T> *node)
	{
		if (NULL == _root)
		{
			_root = node;
			_last = node;
		}
		else
		{
			_last->SetNext(node);
			_last = node;
		}		
		_count++;
	}
	int GetLength()
	{
		return _count;
	}
	Node<T>* GetRoot()
	{
		return _root;
	}
};

template<class T> class Solution
{
private: 
	Node<T>* MoveTo(Node<T>*start, int len)
	{
		auto result = start;
		while (len-- > 0) result = result->GetNext();
		return result;
	}
public:
	Node<T>* Solve(LinkedList<T>& l1, LinkedList<T>&l2)
	{		
		auto len1 = l1.GetLength();
		auto len2 = l2.GetLength();
		
		auto ll1 = MoveTo(l1.GetRoot(), len1 - len2);
		auto ll2 = MoveTo(l2.GetRoot(), len2 - len1);
		
		while (ll1 && ll2)
		{
			if (ll1 == ll2) break;
			ll1 = ll1->GetNext();
			ll2 = ll2->GetNext();
		}
		return ll1;
	}
};

int main()
{
	std::vector<Node<int>*> n1 = { new Node<int>(3) ,new Node<int>(7)};
	std::vector<Node<int>*> n2 = { new Node<int>(99) ,new Node<int>(1),new Node<int>(14),new Node<int>(18) };

	std::vector<Node<int>*> inter = { new Node<int>(8) ,new Node<int>(10) };
			
	LinkedList<int> l1;
	LinkedList<int> l2;

	for (auto i : n1) l1.Add(i);
	for (auto i : inter) l1.Add(i);

	for (auto i : n2) l2.Add(i);
	for (auto i : inter) l2.Add(i);

	Solution<int> s;
	auto result = s.Solve(l1,l2);
	printf("%d", result->GetValue());
	
	return 0;
}


//This problem was asked by Microsoft.
//Suppose an arithmetic expression is given as a binary tree.Each leaf is an integer and each internal node is one of '+', '−', '∗', or '/'.
//Given the root to such a tree, write a function to evaluate it.
//For example, given the following tree :
//
//    *
//   / \
//   + +
//  / \ / \
// 3  2  4  5
//You should return 45, as it is(3 + 2) * (4 + 5).


#include <iostream>
#include <vector>
#include <algorithm>

union BTreeValue
{
	int Value;
	char Operand;
};

class BTreeNode
{
private:
	bool _isOperand;
	BTreeNode()
	{
		LeftChild = NULL;
		RightChild = NULL;	
	}
public: 		
	BTreeNode(int value): BTreeNode()
	{	
		Value.Value = value;
	}
	BTreeNode(char operand) : BTreeNode()
	{	
		Value.Operand = operand;
	}
	BTreeValue Value;
	BTreeNode* LeftChild;
	BTreeNode* RightChild;

	BTreeNode& WithChildren(int left, int right)
	{
		LeftChild = new BTreeNode(left);
		RightChild = new BTreeNode(right);
		return *this;
	}
	BTreeNode& WithChildren(char left, char right)
	{
		LeftChild = new BTreeNode(left);
		RightChild = new BTreeNode(right);
		return *this;
	}

	BTreeNode& WithChildren(BTreeNode* left, BTreeNode* right)
	{
		LeftChild = left;
		RightChild = right;
		return *this;
	}

	int Calculate()
	{	
		if (NULL == LeftChild) return Value.Value; //leaf with integer value
		
		auto leftResult = LeftChild->Calculate();
		auto rightResult = RightChild->Calculate();

		switch (Value.Operand)
		{
		case '+': return leftResult + rightResult;
		case '-': return leftResult - rightResult;
		case '*': return leftResult * rightResult;
		case '/': return leftResult / rightResult;
		default: return 0;
		}		
	}

};

class Solution
{
private:
public:
	int Solve(BTreeNode& node)
	{		
		return node.Calculate();
	}
};

int main()
{
	// create treee from leafs to root
	BTreeNode l1('+');
	l1.WithChildren(3, 2);
	BTreeNode l2('+');
	l2.WithChildren(4, 5);
	BTreeNode root('*');
	root.WithChildren(&l1,&l2);
	

	Solution s;
	auto result = s.Solve(root);
	printf("%d", result);

	return 0;
}

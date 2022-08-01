#pragma once
#include<iostream>
using namespace std;


template<class K>
struct BSTreeNode //BinarySearchTreeNode
{
	BSTreeNode(const K& key)
		:_left(nullptr),_right(nullptr),_key(key)
	{}
	BSTreeNode<K>* _left;
	BSTreeNode<K>* _right;
	K _key;
};

template<class K>
struct BSTree
{
	typedef BSTreeNode<K> Node;
public:
	BSTree()
		:_root(nullptr)
	{}
	//默认情况下搜索树是不容许冗余的，一般情况下不容许插入相同的值，所以有返回值
	bool Insert(const K& key)
	{
		if (_root == nullptr)
		{
			_root = new Node(key);
			return true;
		}
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (key > cur->_key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (key < cur->_key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return false;//重复的值不插入
			}
		}
		cur = new Node(key);
		if (key > parent->_key)
		{
			parent->_right = cur;
		}
		else
		{
			parent->_left = cur;
		}

		return true;
	}

	bool Find(const K& kry)
	{
		Node* cur = _root;
		while (cur)
		{
			if (cur->_key < key)
			{
				cur = cur->_right;
			}
			else if(cur->_key>key)
			{
				cur = cur->_left;
			}
			else
			{
				return true;
			}
		}
		return false;
	}

	bool Erase(const K& key)
	{
		 
	}

	void InOrder()
	{
		_InOrder(_root);//因为根节点是私有的，类外面很难使用，所以套一层子函数
	}

	void _InOrder(Node* root)
	{
		if (root == nullptr)
		{
			return;
		}
		_InOrder(root->_left);
		cout << root->_key << " ";
		_InOrder(root->_right);
	}

private:
	Node* _root;

};

void TestBSTree()
{
	BSTree<int> t;
	int a[] = { 5,3,4,1,7,8,2,6,0,9 };
	for (auto e : a)
	{
		t.Insert(e);
	}
	t.InOrder();
}
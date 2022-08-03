#pragma once
#include<iostream>
#include<algorithm>
using namespace std;

namespace key
{
	template<class K>
	struct BSTreeNode //BinarySearchTreeNode
	{
		BSTreeNode(const K& key)
			:_left(nullptr), _right(nullptr), _key(key)
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




		void InsertR(const K& key)
		{
			_InsertR(_root, key);
		}

		bool EraseR(const K& key)
		{
			return _EraseR(_root, key);
		}

		bool Find(const K& key)
		{
			Node* cur = _root;
			while (cur)
			{
				if (cur->_key < key)
				{
					cur = cur->_right;
				}
				else if (cur->_key > key)
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
			Node* parent = nullptr;
			Node* cur = _root;
			while (cur)
			{
				if (cur->_key < key)
				{
					parent = cur;
					cur = cur->_right;
				}
				else if (cur->_key > key)
				{
					parent = cur;
					cur = cur->_left;
				}
				else //相等找到了
				{
					if (cur->_left == nullptr)  //左子树等于空有两种情况：1.没有孩子  2.只有一个孩子(右孩子)
					{
						if (parent == nullptr)
						{
							_root = cur->_right;
							delete cur;
						}
						else
						{
							//确定是让父亲的left/right指向我的孩子
							if (parent->_left == cur)
							{
								parent->_left = cur->_right;
							}
							else
							{
								parent->_right = cur->_right;
							}
							delete cur;
						}


					}
					else if (cur->_right == nullptr)  //只有一个左孩子
					{
						if (parent == nullptr)
						{
							_root = cur->_left;
							delete cur;
						}
						else
						{
							if (parent->_left = cur)
							{
								parent->_left = cur->_left;
							}
							else
							{
								parent->_right = cur->_left;
							}
						}
						delete cur;
					}
					else  //左右都不为空:替换法删除
					{
						Node* minparent = cur;
						Node* min = cur->_right;
						while (min->_left)
						{
							minparent = min;
							min = min->_left;
						}
						cur->_key = min->_key;
						if (min == minparent->_left)
						{

							minparent->_left = min->_right;
						}
						else
						{
							minparent->_right = min->_right;
						}
						delete min;
					}
					return true;
				}
			}

			return false;
		}

		void InOrder()
		{
			_InOrder(_root);//因为根节点是私有的，类外面很难使用，所以套一层子函数
		}
	private:

		bool _EraseR(Node*& root, const K& key)
		{
			if (root == nullptr)
			{
				return false;
			}
			if (root->_key < key)
			{
				return _EraseR(root->_right, key);
			}
			else if (root->_key > key)
			{
				return _EraseR(root->_left, key);
			}
			else
			{
				Node* del = root;
				if (root->_left == nullptr)
				{
					root = root->_right;
				}
				else if (root->_right == nullptr)
				{
					root = root->_left;
				}
				else
				{
					Node* min = root->_right;
					while (min->_left)
					{
						min = min->_left;
					}
					swap(min->_key, root->_key);
					//递归到右子树删除
					return _EraseR(root->_right, key);
				}
				delete del;
				return true;
			}
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

		bool _InsertR(Node*& root, const K& key)
		{
			if (root == nullptr)
			{
				root = new Node(key);
				return true;
			}
			if (root->_key < key)
			{
				return _InsertR(root->_right, key);
			}
			else if (root->_key > key)
			{
				return _InsertR(root->_left, key);
			}
			else
			{
				return false;
			}
		}

		Node* _FindR(Node* root, const K& key)
		{
			if (root == nullptr)
			{
				return nullptr;
			}
			else if (root->_key > key)
			{
				_FindR(root->_left);
			}
			else if (root->_key < key)
			{
				_FindR(root->_right);
			}
			else
			{
				return root;
			}
		}
	private:
		Node* _root;

	};
}

namespace KV
{
	template<class K,class V>
	struct BSTreeNode //BinarySearchTreeNode
	{
		BSTreeNode(const K& key,const V& value)
			:_left(nullptr), _right(nullptr), _key(key),_value(value)
		{}
		BSTreeNode<K,V>* _left;
		BSTreeNode<K, V>* _right;
		K _key;
		V _value;
	};

	template<class K,class V>
	struct BSTree
	{
		typedef BSTreeNode<K,V> Node;
	public:
		BSTree()
			:_root(nullptr)
		{}
		//默认情况下搜索树是不容许冗余的，一般情况下不容许插入相同的值，所以有返回值
		bool Insert(const K& key,const V& value)
		{
			if (_root == nullptr)
			{
				_root = new Node(key,value);
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
			cur = new Node(key,value);
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



		Node* Find(const K& key)
		{
			Node* cur = _root;
			while (cur)
			{
				if (cur->_key < key)
				{
					cur = cur->_right;
				}
				else if (cur->_key > key)
				{
					cur = cur->_left;
				}
				else
				{
					return cur;
				}
			}
			return nullptr;
		}

		bool Erase(const K& key)
		{
			Node* parent = nullptr;
			Node* cur = _root;
			while (cur)
			{
				if (cur->_key < key)
				{
					parent = cur;
					cur = cur->_right;
				}
				else if (cur->_key > key)
				{
					parent = cur;
					cur = cur->_left;
				}
				else //相等找到了
				{
					if (cur->_left == nullptr)  //左子树等于空有两种情况：1.没有孩子  2.只有一个孩子(右孩子)
					{
						if (parent == nullptr)
						{
							_root = cur->_right;
							delete cur;
						}
						else
						{
							//确定是让父亲的left/right指向我的孩子
							if (parent->_left == cur)
							{
								parent->_left = cur->_right;
							}
							else
							{
								parent->_right = cur->_right;
							}
							delete cur;
						}


					}
					else if (cur->_right == nullptr)  //只有一个左孩子
					{
						if (parent == nullptr)
						{
							_root = cur->_left;
							delete cur;
						}
						else
						{
							if (parent->_left = cur)
							{
								parent->_left = cur->_left;
							}
							else
							{
								parent->_right = cur->_left;
							}
						}
						delete cur;
					}
					else  //左右都不为空:替换法删除
					{
						Node* minparent = cur;
						Node* min = cur->_right;
						while (min->_left)
						{
							minparent = min;
							min = min->_left;
						}
						cur->_key = min->_key;
						cur->_value = min->_value;
						if (min == minparent->_left)
						{

							minparent->_left = min->_right;
						}
						else
						{
							minparent->_right = min->_right;
						}
						delete min;
					}
					return true;
				}
			}

			return false;
		}

		void InOrder()
		{
			_InOrder(_root);//因为根节点是私有的，类外面很难使用，所以套一层子函数
		}
	private:
		void _InOrder(Node* root)
		{
			if (root == nullptr)
			{
				return;
			}
			_InOrder(root->_left);
			cout << root->_key << ":"<<root->_value;
			_InOrder(root->_right);
		}
	private:
		Node* _root;

	};
}

void TestBSTree2()
{
	//统计出现次数
	string arr[] = { "苹果","西瓜","苹果","苹果","苹果","西瓜","草莓","香瓜"};
	KV::BSTree<string, int> countTree;
	for (auto& str : arr)
	{
		KV::BSTreeNode<string, int>* ret = countTree.Find(str);
		if (ret != nullptr)
		{
			ret->_value++;
		}
		else
		{
			countTree.Insert(str, 1);
		}
	}
	countTree.InOrder();

}

void TestBSTree1()
{
	//字典
	KV::BSTree<string, string> dict;
	dict.Insert("sort", "排序");
	dict.Insert("left", "左边");
	dict.Insert("right", "右边");
	dict.Insert("map", "地图,映射");

	string str;
	while (cin>>str)
	{
		KV::BSTreeNode<string, string>* ret = dict.Find(str);
		if (ret)
		{
			cout << "译为:" << ret->_value << endl;
		}
		else
		{
			cout << "词库中未找到" << endl;
		}
	}
}

//void TestBSTree()
//{
//	BSTree<int> t;
//	int a[] = { 5,3,4,1,7,8,2,6,0,9 };
//	for (auto e : a)
//	{
//		t.InsertR(e);
//	}
//	t.InOrder();
//	t.EraseR(4);
//	t.EraseR(1);
//	cout << endl;
//	t.InOrder();
//	cout << endl;
//	for (auto e : a)
//	{
//		t.EraseR(e);
//		t.InOrder();
//		cout << endl;
//	}
//}
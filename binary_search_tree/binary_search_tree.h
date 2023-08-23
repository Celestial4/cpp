#pragma once
#include <iostream>
template<class DataItem>
class BinarySearchTree
{
public:
	BinarySearchTree() = default;
	~BinarySearchTree() {
		empty(root);
	}

private:
	struct BTNode
	{
		DataItem data;
		BTNode* left;
		BTNode* right;

		BTNode() = default;
		BTNode(const BTNode& o) :data(o.data), left(o.left), right(o.right) {}
		BTNode(BTNode&& o) :data(std::move(o.data)), left(o.left), right(o.right) {}
	};

	BTNode* root;
	void insert(DataItem& item, BTNode*& x) {
		if (!x)
			x = new BTNode{ item,nullptr,nullptr };
		if (item < x->data)
			insert(item, x->left);
		else if (item > x->data)
			insert(item, x->right);
	}
	DataItem remove(DataItem& item, BTNode*& x) {
		if (!x)
			return nullptr;
		if (item < x->data)
			return remove(item, x->left);
		else if (item > x->data)
			return remove(item, x->right);
		else
		{
			if (x->left && x->right) {
				BTNode* p = find_min(x->right);
				DataItem ret = x->data;
				x->data = p->data;
				remove(p->data, x->right);
				return ret;
			}
			else
			{
				DataItem ret = x->data;
				BTNode* old = x;
				x = x->left ? x->left : x->right;
				delete old;
				return ret;
			}
		}
	}
	void empty(BTNode*& x) {
		if (x->left)
			empty(x->left);
		if (x->right)
			empty(x->right);
		BTNode* old = x;
		x = nullptr;
		delete old;
	}
	bool contains(const DataItem& item, BTNode*& x) {
		if (!x)
			return false;
		else if (item < x->data)
			return contains(x, x->left);
		else if (item > x->data)
			return contains(x, x->right);
		else
			return true;
	}
	BTNode* find_max(BTNode* x) {
		if (!x)
			return nullptr;
		if (x->right)
			return find_max(x->right);
		else
			return x;
	}
	BTNode* find_min(BTNode* x) {
		if (!x)
			return nullptr;
		if (x->left)
			return find_max(x->left);
		else
			return x;
	}
};



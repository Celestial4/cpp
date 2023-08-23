#include "../include/header.h"

using node = tree::TreeNode;

void construct_tree(node *&p)
{
    int t;
    std::cin >> t;
    node *n;
    if (t != -1)
    {
        n = new node;
        n->val = t;
        n->left = n->right = nullptr;
    }
    else
    {
        return;
    }
    construct_tree(n->left);
    construct_tree(n->right);
    p = n;
}

node *construct_tree_2()
{
    int t;
    std::cin >> t;
    if (t == -1)
    {
        return nullptr;
    }
    node *p = new node;
    p->val = t;
    p->left = construct_tree_2();
    p->right = construct_tree_2();
    return p;
}
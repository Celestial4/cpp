#include "../include/header.h"
#include "../include/tree.h"

using node = tree::TreeNode;

bool _solve_100(node *p, node *q)
{
    if (p == nullptr && p == q)
    {
        return true;
    }
    else if (p == nullptr || q == nullptr)
    {
        return false;
    }
    else
    {
        if (p->val == q->val)
        {
            return _solve_100(p->left, q->left) && _solve_100(p->right, q->right);
        }
        else
        {
            return false;
        }
    }
}

void solveSameTree()
{
    node *p = new node, *p2 = new node;
    construct_tree(p);
    construct_tree(p2);
    std::cout << _solve_100(p, p2);
}
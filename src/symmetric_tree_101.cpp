#include "../include/header.h"
#include "../include/tree.h"
using node = tree::TreeNode;
void reverse_tree(node *root)
{
    if (root)
    {
        reverse_tree(root->left);
        reverse_tree(root->right);
        node *t = root->left;
        root->left = root->right;
        root->right = t;
    }
}

bool is_same(node *p, node *q)
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
            return is_same(p->left, q->left) && is_same(p->right, q->right);
        }
        else
        {
            return false;
        }
    }
}

void solve_symmetric_tree_101(node *root)
{
    if (!root)
    {
        std::cout << "true";
    }
    node *l = root->left;
    reverse_tree(l);
    std::cout << is_same(l, root->right) ? "true" : "false";
}
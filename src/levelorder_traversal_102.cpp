#include "../include/header.h"

using node = tree::TreeNode;

using namespace std;

vector<vector<int>> levelorder_traversal(node *root)
{
    vector<vector<int>> res;
    queue<node *> queue;
    queue.push(root);
    while (!queue.empty())
    {
        int len = queue.size();
        vector<int> temp;
        for (size_t i = 0; i < len; i++)
        {
            node *c = queue.front();
            if (c->left)
                queue.push(c->left);
            if (c->right)
                queue.push(c->right);
            queue.pop();

            temp.push_back(c->val);
        }
        res.push_back(temp);
    }
    return res;
}

void solve_levelorder_traversal_101(){
    
}
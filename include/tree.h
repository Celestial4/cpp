namespace tree
{

    struct TreeNode
    {
        int val;
        TreeNode *left;
        TreeNode *right;
    };
}
void construct_tree(tree::TreeNode *&p);

tree::TreeNode *construct_tree_2();

class Solution {
    int idx=0;
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return build(INT_MIN, INT_MAX, preorder);
    }
    TreeNode* build(int lower, int upper, vector<int>& preorder)
    {
        if (idx>=preorder.size())
            return nullptr;
        int val=preorder[idx];
        if (val<lower || val>upper)
            return nullptr;
        idx++;
        TreeNode* node=new TreeNode(val);
        node->left=build(lower, val, preorder);
        node->right=build(val, upper, preorder);
        return node;
    }
};

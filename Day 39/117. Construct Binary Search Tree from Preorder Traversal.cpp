class Solution {
    int idx=0; //ensures we only move forward through the preorder list once
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return build(INT_MIN, INT_MAX, preorder); //to allow any root value initially
    }
    TreeNode* build(int lower, int upper, vector<int>& preorder)
    { //Constructs the subtree using the preorder traversal values within [lower, upper]
        if (idx>=preorder.size())
            return nullptr;
        int val=preorder[idx];
         if (val<lower || val>upper) //If current value is out of the allowed bounds for this subtree
            return nullptr;
        idx++;
        TreeNode* node=new TreeNode(val);
        node->left=build(lower, val, preorder); //Allowed values are less than the current node’s value
        node->right=build(val, upper, preorder); //Allowed values are greater than the current node’s value
        return node;
    }
};
//TC O(N)
//SC O(logn)  or O(n) worst case

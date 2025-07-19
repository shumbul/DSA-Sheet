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

class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if (preorder.size()==0)
            return nullptr;
       return helper(preorder, 0, preorder.size()-1);
      
    }
    TreeNode* helper(vector<int>& preorder, int start, int end)
    { //[start, end] represents the current subtree being built.
        if (start>end)
            return nullptr;
        TreeNode* root=new TreeNode(preorder[start]); //The first element in the current range is always the root of the subtree
       // Find the first element greater than root (start of right subtree)
        int i = start + 1;
        while (i <= end && preorder[i] < preorder[start]) {
            i++;
        }
        root->left=helper(preorder, start+1, i-1);
        root->right=helper(preorder, i, end);
        return root;
    }
};

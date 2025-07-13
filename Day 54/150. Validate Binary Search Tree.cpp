class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return validate(root, LONG_MIN, LONG_MAX); //LONG_MIN and LONG_MAX are used to initialize the valid range for values
    }
    bool validate(TreeNode* node, long minVal, long maxVal) 
    { //minVal and maxVal define the range of valid values the node->val is allowed to be in
        if (!node)
            return true; //A null tree is considered a valid BST.
        if (node->val <= minVal || node->val >= maxVal)
            return false;
        return validate(node->left, minVal, node->val) && validate(node->right, node->val, maxVal); //The valid range gets narrower as you go down the tree.
    }
};

class Solution {
public:
    bool isValidBST(TreeNode* root, long minm = LONG_MIN, long maxm = LONG_MAX) {
        if (!root)
            return true;
        if (root->val <= minm || root->val >= maxm)
            return false;
        return isValidBST(root->left, minm, root->val) && isValidBST(root->right, root->val, maxm);
    }
};

class Solution {
public:
    bool isValidBST(TreeNode* root, long long minm=LONG_LONG_MIN, long long maxm=LONG_MAX) {
        if (!root)
            return true;
        if (root->val<=minm || root->val>=maxm)
            return false;
        return isValidBST(root->left, minm, min(maxm, (long long)root->val)) && isValidBST(root->right, max(minm, (long long)root->val), maxm);
    }
};

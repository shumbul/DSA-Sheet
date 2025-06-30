class Solution {
   int ans=0;
public:
    int sumRootToLeaf(TreeNode* root, int bSum=0) {
        //bSum holds the binary number in progress (as an integer) as we traverse down a path
        if (!root)
            return 0;
        bSum=(bSum*2)+root->val;
        //left shift+0 or 1
        if (!root->left && !root->right)
        {
            
        ans+=bSum;
        }
        sumRootToLeaf(root->left, bSum);
        sumRootToLeaf(root->right, bSum);
        return ans;
    }
};

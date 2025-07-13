class Solution {
    vector<int> sorted;
public:
    int getMinimumDifference(TreeNode* root) {
        if (!root)
            return 0;
        getMinimumDifference(root->left);
        sorted.push_back(root->val);
        getMinimumDifference(root->right);
        int diff=INT_MAX;
        for (int i=0;i<sorted.size()-1;i++)
        { // go through the sorted array (which has the tree's values in ascending order), and calculate the minimum difference between adjacent values.
            if (abs(sorted[i]-sorted[i+1])<diff)
                diff=abs(sorted[i]-sorted[i+1]);
        }
        return diff;
    } 
};

class Solution {
    vector<int> sorted;
public:
    int getMinimumDifference(TreeNode* root) {
        if (!root)
            return 0;
        int diff=INT_MAX;
        traverse(root); //performs an in-order traversal of the BST and stores all values
      /*After the in-order traversal, the sorted vector will contain all BST node values in ascending order.
        Loop through adjacent pairs in sorted, calculate their absolute difference, and update diff if a smaller difference is found.
        Since BST in-order gives sorted values, the minimum difference will always lie between two adjacent nodes in the traversal.*/
        for (int i=0;i<sorted.size()-1;i++)
        {
            if (abs(sorted[i]-sorted[i+1])<diff)
                diff=abs(sorted[i]-sorted[i+1]);
        }
        return diff;
    }
    void traverse(TreeNode* root)
    {
         if (!root)
         return;
        traverse(root->left);
        sorted.push_back(root->val);
        traverse(root->right);
    }
};
//TC O(N)
//SC O(N)

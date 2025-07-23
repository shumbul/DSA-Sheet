/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return buildTree(0, nums.size()-1, nums); //to construct the tree from the full range of the array
    }
    int findMaxElement(vector<int>& nums, int start, int end) //O(n)
    {
        int maxnum=INT_MIN;
        int maxidx=0;
        for (int i=start;i<=end;i++)
        {
            if (maxnum<nums[i])
            {
                maxnum=nums[i];
                maxidx=i;
            } 
        }
        return maxidx;
    }
    TreeNode* buildTree(int start, int end, vector<int>& nums) //O(n)
    {
        if (start>end)
            return nullptr;
        int rootidx=findMaxElement(nums, start, end); //Find the index of the maximum element in the current subarray. This becomes the root of the current subtree.
        TreeNode* node=new TreeNode(nums[rootidx]);
        node->left=buildTree(start, rootidx-1, nums);
        node->right=buildTree(rootidx+1, end, nums);
        return node;
    }
};
//TC: O(n^2)

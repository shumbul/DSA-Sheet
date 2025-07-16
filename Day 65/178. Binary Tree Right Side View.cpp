class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (!root)
        return {};
        queue<TreeNode*> nodes;
        vector<int> ans; //last node of each level
        nodes.push(root);
        while (!nodes.empty())
        {
            int len=nodes.size(); //Stores the number of nodes at the current level. This helps us identify the last node in each level.
            for (int i=0;i<len;i++)
            {
                TreeNode* newNode=nodes.front();
                nodes.pop();
                if (i==len-1) //The last node in each level 
                {
                    ans.push_back(newNode->val);
                }
                if (newNode->left)
                    nodes.push(newNode->left);
                if (newNode->right)
                    nodes.push(newNode->right);
            }
        }
        return ans;
    }
};

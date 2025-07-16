class Solution {
    vector<int> ans;
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if (!root)
            return {};
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        ans.push_back(root->val);
        return ans;
    }
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if (!root) 
            return {};
        stack<TreeNode*> s1, s2;
        vector<int> result;
        s1.push(root);
        while (!s1.empty()) {
            TreeNode* curr = s1.top();
            s1.pop();
            s2.push(curr);
            if (curr->left) 
                s1.push(curr->left);
            if (curr->right) 
                s1.push(curr->right);
        }
        while (!s2.empty()) {
            result.push_back(s2.top()->val);
            s2.pop();
        }
        return result;
    }
};

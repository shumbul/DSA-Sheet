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

//you only visit the root after visiting everything else. Unlike preorder/inorder, you can't "visit as you go"
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* curr = root;
        while (curr != nullptr) {
            if (curr->right == nullptr) {
                // No left subtree, visit current node and go right
                ans.push_back(curr->val);
                curr = curr->left;
            } 
            else {
                // Find the inorder prev
                TreeNode* prev = curr->right;
                while (prev->left != nullptr && prev->left != curr) {
                    prev = prev->left;
                }  
                if (prev->left == nullptr) {
                    // Create thread to curr node
                    ans.push_back(curr->val);
                    prev->left = curr;
                    curr = curr->right;
                } 
                else {
                    // Thread already exists, remove it and visit curr node
                    prev->left = nullptr;
                   // ans.push_back(curr->val);
                    curr = curr->left;
                }
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
//root->right->left reverse
//left->right->root

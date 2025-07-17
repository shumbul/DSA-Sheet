class Solution {
     vector<int> ans;
public:
    vector<int> preorderTraversal(TreeNode* root) {
       
        if (!root)
            return {};
        ans.push_back(root->val);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
        return ans;
    }
};

class Solution {
  public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if (!root) 
            return result;
        stack<TreeNode*> st;
        st.push(root);
        while (!st.empty()) {
            TreeNode* curr = st.top();
            st.pop();
            result.push_back(curr->val); // Visit root
            // Push right first so left is processed first
            if (curr->right) 
                st.push(curr->right);
            if (curr->left)  
                st.push(curr->left);
        }
        return result;
    }
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* curr = root;
        while (curr != nullptr) {
            if (curr->left == nullptr) {
                // No left child: visit and go right
                ans.push_back(curr->val);
                curr = curr->right;
            } 
            else {
                // Find the inorder predecessor
                TreeNode* prev = curr->left;
                while (prev->right != nullptr && prev->right != curr) {
                    prev = prev->right;
                }
                if (prev->right == nullptr) {
                    // First time visiting: make thread and visit
                    ans.push_back(curr->val); // visit before going left (preorder)
                    prev->right = curr; // create thread
                    curr = curr->left;
                } 
                else {
                    // Thread exists: remove it and go right
                    prev->right = nullptr;
                    curr = curr->right;
                }
            }
        }
        return ans;
    }
};

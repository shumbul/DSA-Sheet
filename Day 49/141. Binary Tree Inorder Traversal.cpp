class Solution {
     vector<int> ans;
public:
    vector<int> inorderTraversal(TreeNode* root) {
        //inorder means left->root->right
        if (!root)
            return {};
        inorderTraversal(root->left);
        ans.push_back(root->val);
        inorderTraversal(root->right);
        return ans;
    }
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> nodes; //to simulate the recursive call stack.
        vector<int> ans;
        TreeNode* node=root;
        while (node || !nodes.empty())
        {
            if (node) //If the current node exists:
            {
            nodes.push(node); //Push it to the stack (we’ll come back to it later to process its value).
            node=node->left; //Move to its left child to go as left as possible 
            }
            else //We’ve hit the leftmost node.
            {
                TreeNode* newNode=nodes.top();
                ans.push_back(newNode->val);
                nodes.pop(); //Pop the parent of the last left node).
                node=newNode->right; //move to its right child to process the Right subtree next
            }
        }
        return ans;
    }
};
//TC O(N)
//SC O(H+N)

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

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* curr = root; //used to traverse the tree without recursion
        while (curr != nullptr) {
            if (curr->left == nullptr) {
                // No left subtree, visit current node and go right
                ans.push_back(curr->val);
                curr = curr->right;
            } 
            else {
          /* we need a way to come back to curr after finishing its left subtree.
          To do that We find the inorder predecessor (prev) of curr.
          We make a temporary connection: prev->right = curr
          This acts like a thread so we can return to curr after we’ve visited everything on the left. */
                TreeNode* prev = curr->left;
                while (prev->right != nullptr && prev->right != curr) {
               /*Keep moving to the rightmost node of the left subtree — but stop if you either reach the end (nullptr) or you find a thread already pointing back to the current node (curr).
               2nd condition is to stop the loop if we have already created the thread before
               Prevents an infinite loop.
               Identifies that we’ve visited this left subtree already.
               Acts like a marker to know when to stop going right */
                    prev = prev->right;
                }  
                if (prev->right == nullptr) {
                    // Create thread to curr node
                    prev->right = curr;
                    curr = curr->left;
                } 
                else {
                    // Thread already exists, remove it and visit curr node
                    prev->right = nullptr;
                    ans.push_back(curr->val);
                    curr = curr->right;
                }
            }
             /*Why the else case? We already visited it?
             No — we hadn’t visited that node yet, because we went to its left subtree first.
             We created a thread from to remember to come back.
             So when the node finishes, we follow the thread, and now we're back
             Now We break the thread, We visit root node, Move to curr 
             ✅ The point is We revisit curr after finishing its left subtree, using the thread we created in its prev.
             This replaces the role of the call stack or explicit stack in recursive/iterative inorder traversal.*/
        }
        return ans;
    }
};

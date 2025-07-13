class Solution {
    int sum = 0;

public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root)
            return 0;
        queue<TreeNode*> nodes;
        nodes.push(root);
        while (!nodes.empty()) {
            auto front = nodes.front();
            nodes.pop();
            if (front->left) //if current node has a left child
            {
                if (!front->left->left && !front->left->right) //if left child is a leaf node then add it
                    sum+=front->left->val;
                nodes.push(front->left);
            }
            if (front->right) //if current node has a right child
                nodes.push(front->right);
        }
        return sum;
    }
};
//TC O(N)
//SC O(width)

class Solution {
    int sum=0;
public:
    int sumOfLeftLeaves(TreeNode* root, bool isLeft=false) 
    { //to indicate if the current node is a left child.
      //Default value is false since the root is not considered a left child.
        if (!root)
            return 0;
        if (!root->left && !root->right && isLeft)
          //current node is a leaf node && it was reached via a left edge
            sum+=root->val;
        sumOfLeftLeaves(root->left, true); //marking the next node as reached via a left edge
        sumOfLeftLeaves(root->right, false);
        return sum;
    }
};

class Solution {
    int sum=0;
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root)
            return 0;
        if (root->left && !root->left->left && !root->left->right)
          //If the current node has a left child, and That left child has no children
            sum+=root->left->val;
        sumOfLeftLeaves(root->left);
        sumOfLeftLeaves(root->right);
        return sum;
    }
};

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if ((!p && q) || (p && !q))
            return false;
        if (!p && !q)
            return true;
        if (p->val!=q->val)
            return false;
        bool ans1=isSameTree(p->left, q->left);
        bool ans2=isSameTree(p->right, q->right);
        return (ans1 && ans2);
    }
};

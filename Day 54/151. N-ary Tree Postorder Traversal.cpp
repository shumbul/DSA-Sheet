//left->right->root
class Solution {
    vector<int> ans;
public:
    vector<int> postorder(Node* root) {
        if (!root)
            return {};
        for (Node* i : root->children) {
            postorder(i);
        }
        ans.push_back(root->val);
        return ans;
    }
};

class Solution {
    vector<int> ans;
public:
    vector<int> preorder(Node* root) {
        if (!root)
            return {};
        ans.push_back(root->val); //preorder means process the node before its children
        for (Node* i : root->children) {
            preorder(i);
        }
        return ans;
    }
};

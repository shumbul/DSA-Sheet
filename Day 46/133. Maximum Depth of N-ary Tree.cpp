class Solution {
public:
    int maxDepth(Node* root) {
        if (!root)
            return 0;
        int ans=0;
        for (auto child:root->children)
        { //Loops through each child node in root->children
            int depth=maxDepth(child);
            ans=max(depth, ans);
        }
        return 1+ans; //include current node
    }
};
//TC O(N)
//SC O(H)

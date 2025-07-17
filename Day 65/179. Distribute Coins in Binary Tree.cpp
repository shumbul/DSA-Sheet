class Solution {
public:
    int distributeCoins(TreeNode* root) {
        if (!root)
            return 0;
        int moves=0;
        helper(root, moves);
        return moves;
    }
    int helper(TreeNode* node, int& moves)
    {
       if (!node)
            return 0;
        int leftsum=helper(node->left, moves);
        int rightsum=helper(node->right, moves);
        int excesscoins=node->val+leftsum+rightsum-1; //we are doing -1 because atleast 1 is already assigned to the current node. If this value is -ve then this node needs these many coins
        moves+=abs(leftsum)+abs(rightsum); //abs because order is not known
        // leaf has no child to receive or give coins to — so no actual move occurs at the leaf and moves is 0. Even if leaf needs coins or has extra coins, the actual movement will happen between the leaf and its parent.
        return excesscoins;
    }
};
//recursion in tree is o(n) because each node is being visited only once and there are no overlapping subproblems

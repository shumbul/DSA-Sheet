class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> weights(stones.begin(), stones.end());
        while (weights.size()>1)
        {
            helper(weights);
        }
        if (weights.size()==0)
            return 0;
        return weights.top();
    }
    void helper(priority_queue<int>& weights)
    {
        int y=weights.top();
        weights.pop();
        int x=weights.top();
        weights.pop();
        if (x==y)
            return;
        if (x<y)
        {
            weights.push(y-x);
            return;
        }
    }
};

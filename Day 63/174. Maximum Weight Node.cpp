// User function Template for C++
class Solution {
  public:
    int maxWeightCell(vector<int> &exits) {
        // code here
        int ans=0;
        vector<int> weights(exits.size(), 0);
        for (int i=0;i<exits.size();i++)
        {
            if (exits[i]==-1)
                continue;
            weights[exits[i]]+=i;
        }
        int it=*max_element(weights.begin(), weights.end());
        for (int i=0;i<weights.size();i++)
        {
            if (weights[i]==it)
                ans= i;
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>ans;
        for (int i=0;i<=n;i++)
        {
            ans.push_back(count1s(i));
        }
        return ans;
    }
    int count1s(int n)
    {
         int count=0;
        while (n)
        {
            count+=n&1; //if lsb is 1 then count is increased
            n=n>>1; //removes right most bit for next iteration
        }
        return count;
    }
};

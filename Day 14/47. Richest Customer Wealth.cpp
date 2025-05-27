class Solution 
{
public:
    int maximumWealth(vector<vector<int>>& accounts) 
    {
        int sum=0, ans=0;
        for (int i=0;i<accounts.size();i++)
        {
            for (int j=0;j<accounts[0].size();j++)
            {
                sum+=accounts[i][j];
            }
            if (sum>ans)
            {
                ans=sum;
            }
            sum=0;
        }
        return ans;
    }
};
//row- customer
//col- bank
//TC O(n^2)
//SC O(1)

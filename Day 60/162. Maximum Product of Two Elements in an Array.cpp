class Solution {
public:
    int maxProduct(vector<int>& nums) {
        priority_queue<int> ans(nums.begin(), nums.end());
        int n=2;
        int multi=1;
        while (n--)
        {
            multi=multi*(ans.top()-1);
            ans.pop();
        }
        return multi;
    }
};

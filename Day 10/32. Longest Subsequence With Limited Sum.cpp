class Solution 
{
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) 
    {
        vector<int> ans;
        sort(nums.begin(), nums.end()); //you want to add the smallest elements first to maximize how many you can include without exceeding the sum.
        for (int i = 0; i < queries.size(); i++) 
        {
            int sum = 0; //sum of selected nos.
            int count = 0; //no of selected nos.
            for (int j = 0; j < nums.size(); j++) 
            {
                if (sum + nums[j] <= queries[i]) //add only if feasible
                {
                    sum += nums[j];
                    count++;
                } 
                else 
                {
                    break; // stop early once sum exceeds query
                }
            }
            ans.push_back(count);
        }
        return ans;
    }
};
//TC=O(nlogn+mn)
//SC O(m)
//n=nums.size(), m=queries.size()

class Solution 
{
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) 
    {
        sort(nums.begin(), nums.end()); // Sort to pick smallest elements first
        int n = nums.size();
        // Build prefix sum array
        vector<int> prefix(n);
        prefix[0] = nums[0];
        for (int i = 1; i < n; i++) 
        {
            prefix[i] = prefix[i - 1] + nums[i];
        }
        vector<int> result;
        for (int q : queries) 
        {
            // Binary search: how many elements have prefix sum ≤ q
            int left = 0, right = n - 1;
            int res = 0; //no of elements we can include for the current query
            while (left <= right) 
            {
                int mid = left + (right - left) / 2;
                if (prefix[mid] <= q) 
                {
                    res = mid + 1; // +1 because res is length, not index
                    left = mid + 1;
                } 
                else 
                {
                    right = mid - 1;
                }
            }
            result.push_back(res);
        }
        return result;
    }
};
//TC O(nlogn)
//SC O(n)

//Use a monotonic stack that stores elements in decreasing order and simulate the circular array by doubling its size (virtually).
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        vector<int> ans;
        int n=nums.size();
        for (int i=0;i<n;i++)
        { // simulates the circular nature of the array by appending the entire array to itself
            nums.push_back(nums[i]);
        }
        for (int i=nums.size()-1;i>=0;i--)
        {
            while (!st.empty() && st.top()<=nums[i])
            {
                st.pop(); //We only want to keep elements greater than the current number, as potential answers.
            }
            if (st.empty())
            {
                st.push(nums[i]);
                ans.push_back(-1);
            }
            else
            {
                ans.push_back(st.top()); //If a greater element exists
                st.push(nums[i]); //push the current element to stack for future comparisons.
            }
        }
    reverse(ans.begin(), ans.end()); //We were processing from end to start
        ans.resize(n); //we only want answers for the original array.
        return ans;
    }
};
//TC  O(N)
//SC O(N)

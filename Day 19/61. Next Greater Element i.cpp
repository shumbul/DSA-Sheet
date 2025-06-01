class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size())
            return {};
        vector<int> ans;
        int n = nums1.size();
        int m = nums2.size();
        int k = -1; // store position in nums2 just after the matching nums1[i]
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (nums1[i] == nums2[j]) {
                    k = j + 1; //start searching for the next greater element after that index.
                    break;
                }
            }
            if (k != -1) {
                while (k < m) {
                    if (nums2[k] > nums1[i]) {
                        ans.push_back(nums2[k]);
                        break;
                    }
                    k++;
                }
            }
            if (ans.size() != i + 1)
                ans.push_back(-1);
        }
        return ans;
    }
};
//TC O(n^2)
//SC O(n)

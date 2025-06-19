class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        unordered_set<int> nums;
        int ans = 0;
        int n = digits.size();
        for (int i = 0; i < n; i++) { //hundred's place
            for (int j = 0; j < n; j++) { //ten's place
                for (int k = 0; k < n; k++) { //one's place
                    if (i == k || i == j || j == k) //can't use same digit twice
                        continue;
                    if (digits[i] == 0) 
                        continue;
                    if (digits[k] % 2 != 0)
                        continue;
                    int num = digits[i] * 100 + digits[j] * 10 + digits[k]; //form the number
                    if (nums.count(num) == 0) {
                        nums.insert(num);
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};

//TC O(N^3)
//SC O(N^3)

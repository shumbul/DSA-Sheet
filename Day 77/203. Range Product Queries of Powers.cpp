class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        const int MOD = 1000000007;
        vector<int> powers;
        // Build the 'powers' array from the binary representation of n
        for (int bit = 0; bit < 31; bit++) {
            if (n & (1 << bit)) {
                powers.push_back(1 << bit);
            }
        }
        // Process each query by direct product calculation
        vector<int> answer;
        answer.reserve(queries.size());
        for (auto q : queries) {
            int l = q[0], r = q[1];
            long long prod = 1;
            for (int i = l; i <= r; i++) {
                prod = (prod * powers[i]) % MOD;
            }
            answer.push_back((int)prod);
        }
        return answer;
    }
};

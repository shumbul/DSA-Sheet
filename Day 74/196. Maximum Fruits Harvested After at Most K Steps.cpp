class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size();
        vector<int> positions(n);
        vector<int> prefixSum(n);
        for (int i = 0; i < n; i++) {
            positions[i] = fruits[i][0];
            if (i > 0)
                prefixSum[i] = prefixSum[i - 1] + fruits[i][1];
            else
                prefixSum[i] = fruits[i][1];
        }
        int maxFruits = 0;
        for (int d = 0; d <= k / 2; d++) // k-2d>=0
        {
            // case 1- left then right
            int remain = k - 2 * d;
            int i = startPos - d;
            int j = startPos + remain;
            int left = lower_bound(positions.begin(), positions.end(), i) - positions.begin();
            int right = upper_bound(positions.begin(), positions.end(), j) - positions.begin() - 1;
            if (left <= right) {
                int sum = 0;
                if (left > 0)
                    sum = prefixSum[right] - prefixSum[left - 1];
                else
                    sum = prefixSum[right];
                maxFruits = max(maxFruits, sum);
            }
            // case 2- right to left
            j = startPos + d;
            i = startPos - remain;
            left = lower_bound(positions.begin(), positions.end(), i) - positions.begin();
            right = upper_bound(positions.begin(), positions.end(), j) - positions.begin() - 1;
            if (left <= right) {
                int sum = 0;
                if (left > 0)
                    sum = prefixSum[right] - prefixSum[left - 1];
                else
                    sum = prefixSum[right];
                maxFruits = max(maxFruits, sum);
            }
        }
        return maxFruits;
    }
};

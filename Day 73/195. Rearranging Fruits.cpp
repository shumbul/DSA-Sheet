class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int, int> freq1, totalFreq;
        // Step 1: Calculate the net difference of each fruit type
        for (int i = 0; i < basket1.size(); i++) {
            freq1[basket1[i]]++;   
            freq1[basket2[i]]--;
          /*freq1[fruit] > 0: means extra copies of fruit in basket1.
          freq1[fruit] < 0: means extra copies of fruit in basket2.*/
            totalFreq[basket1[i]]++;
            totalFreq[basket2[i]]++;
        }
        // Step 2: Check if every fruit type appears even number of times overall
        for (auto [fruit, count] : totalFreq) {
            if (count % 2 != 0) 
                return -1; // Impossible to equalize baskets
        }
        // Step 3: figure out which fruits and how many times need to be swapped between basket1 and basket2 to make them identical.
        vector<int> extras;
        for (auto [fruit, count] : freq1) {
            if (count != 0) {
                int moves = abs(count) / 2; //Each imbalance must be resolved with a swap. Since each swap moves one fruit from one basket to another, we need half the imbalance to fix it.
                for (int i = 0; i < moves; i++) //We need to know which specific fruits are surplus and need to be swapped
                  {
                    extras.push_back(fruit); //The swap cost depends on the actual fruit values
                  }
            }
        }
        // Step 4: Sort extras so we can choose cheapest values to swap
        sort(extras.begin(), extras.end());
        // Step 5: Instead of swapping two large fruits directly, you can "simulate" replacing both with two of the smallest fruit (swap each with the smallest one), potentially reducing the cost.
        int global_min = min(*min_element(basket1.begin(), basket1.end()), *min_element(basket2.begin(), basket2.end()));
        // Step 6: Calculate minimum cost
        long long cost = 0;
        int n = extras.size();
        for (int i = 0; i < n / 2; i++) {
          /*You are about to swap two fruits. for every swap:
          Option 1: Swap the two fruits directly
           Cost = min(fruit1, fruit2)
          Option 2: Replace both fruits indirectly using the smallest fruit in all baskets
            Cost = min(fruit1, global_min) + min(fruit2, global_min)
          Since global_min is smaller than both, this becomes: global_min + global_min = 2 * global_min
            cost += min(direct_swap_cost, indirect_swap_cost)*/
            cost += min(extras[i], 2 * global_min);
        }
        return cost;
    }
};
//TC: O(nlogn)
//SC: O(n)

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        vector<bool> used(n, false);
        int unplaced = n; //Start by assuming all fruits are unplaced.
        for (int fruit : fruits) {
            for (int i = 0; i < n; i++) { //For each fruit, try every basket
                if (!used[i] && baskets[i] >= fruit) 
                { //If basket i is not used AND it can hold this fruit.
                    used[i] = true;
                    unplaced--; //Successfully placed one fruit
                    break;
                }
            }
        }
        return unplaced;
    }
};

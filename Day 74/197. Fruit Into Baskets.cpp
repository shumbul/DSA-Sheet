class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> basket; //keeps track of how many fruits of each type you currently have in your window.
        int left = 0; //start of your sliding window.
        int maxLen = 0; //will store the maximum number of fruits collected with at most 2 types.
        for (int right = 0; right < fruits.size(); right++) 
        { //expanding the window by moving the right pointer forward.
            basket[fruits[right]]++;
            while (basket.size() > 2) 
            {
                basket[fruits[left]]--; //shrink the window from the left side until you're back to 2 or fewer types.
                if (basket[fruits[left]] == 0) //that fruit type is completely removed from the basket.
                    basket.erase(fruits[left]);
                left++; //shrink window
            }
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};
//TC O(N)
//SC O(1)

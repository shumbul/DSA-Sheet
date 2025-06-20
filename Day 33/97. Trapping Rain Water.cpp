class Solution {
public:
    int trap(vector<int>& height) 
    {
        int maxHeight = *max_element(height.begin(), height.end());
        int total = 0;
        int n = height.size();
        for (int level = 1; level <= maxHeight; level++) 
        {
            bool isBoundStarted = false; //to track whether you've found the left wall of a water-trapping region
            int temp = 0;
            for (int i = 0; i < n; i++) 
            {
                if (height[i] >= level) 
                {
                    //if a left boundary has started and now we find another wall, add trapped water
                    if (isBoundStarted) 
                    {
                        total += temp;
                        temp = 0;
                    } 
                    else 
                        isBoundStarted = true; //start counting between walls
                } 
                else if (isBoundStarted) 
                    temp++;  //a space that can trap water
            }
        }
        return total;
    }
};
//TC O(N^2)
//SC O(1)

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int total = 0;
        // For each index, try to trap water
        for (int i = 0; i < n; i++) {
            int leftMax = findLeftMax(height, i);
            int rightMax = findRightMax(height, i);
            int water = min(leftMax, rightMax) - height[i];
            if (water > 0) //if not, the result is <= 0, which means no water
                totalWater += water;
        }
        return totalWater;
    }
    int findLeftMax(vector<int>& height, int i) {
        int maxLeft = 0;
        for (int j = i - 1; j >= 0; j--) {
            maxLeft = max(maxLeft, height[j]);
        }
        return maxLeft;
    }
    int findRightMax(vector<int>& height, int i) {
        int maxRight = 0;
        for (int j = i + 1; j < height.size(); j++) {
            maxRight = max(maxRight, height[j]);
        }
        return maxRight;
    }
};
//TC O(N^2)
//SC O(1)

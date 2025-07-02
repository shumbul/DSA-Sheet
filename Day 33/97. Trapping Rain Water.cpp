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
        for (int i = 0; i < n; i++) { //O(N)
            int leftMax = findLeftMax(height, i);
            int rightMax = findRightMax(height, i);
            int water = min(leftMax, rightMax) - height[i];
            if (water > 0) //if not, the result is <= 0, which means no water
                totalWater += water;
        }
        return totalWater;
    }
    int findLeftMax(vector<int>& height, int i) { // O(n)
        int maxLeft = 0;
        for (int j = i - 1; j >= 0; j--) {
            maxLeft = max(maxLeft, height[j]);
        }
        return maxLeft;
    }
    int findRightMax(vector<int>& height, int i) { // O(m)
        int maxRight = 0;
        for (int j = i + 1; j < height.size(); j++) {
            maxRight = max(maxRight, height[j]);
        }
        return maxRight;
    }
};
//TC O(N)*O(n+m)
//SC O(1)

class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> prefix(height.size());
        vector<int> suffix(height.size());
        int total=0;
        int water=0;
        prefix[0]=height[0];
        suffix[height.size()-1]=height[height.size()-1];
        for (int i=1;i<height.size();i++)
        {
            prefix[i]=max(prefix[i-1], height[i]);
        }
         for (int i=height.size()-2;i>=0;i--)
        {
            suffix[i]=max(suffix[i+1], height[i]);
        }
        for (int i=0;i<height.size();i++)
        {
           water=min(prefix[i], suffix[i])-height[i];
           if (water>0)
            total+=water;
        }
        return total;
    }
};
//O(3n)

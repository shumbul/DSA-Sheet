class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n), right(n);
        stack<int> st;
        for (int i = 0; i < n; ++i) 
        {
            while (!st.empty() && heights[st.top()] >= heights[i])
            {
                st.pop(); //we want the nearest strictly smaller bar on the left
            }
            if (st.empty())
                left[i] = -1;
            else
                left[i] = st.top(); //top of the stack is the index of the nearest smaller to the left
            st.push(i);
        }
        while (!st.empty()) //clear the stack before reusing it
        {
            st.pop();
        }
        for (int i = n - 1; i >= 0; --i) 
        {
            while (!st.empty() && heights[st.top()] >= heights[i])
            {
                st.pop(); //pop elements greater than or equal to the current bar
            }
            if (st.empty())
                right[i] = n;
            else
                right[i] = st.top(); //assign the index of the smaller bar on the right
            st.push(i);
        }
        int maxArea = 0;
        for (int i = 0; i < n; ++i) 
        {
            int width = right[i] - left[i] - 1; //number of bars between NSL and NSR
            int area = heights[i] * width;
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }
};
//TC O(N)
//SC O(N)

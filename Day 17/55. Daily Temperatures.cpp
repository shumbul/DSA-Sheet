class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> answer(temperatures.size(), 1);
        int j=1; //to look ahead from day i to find a warmer temp
        for (int i=0;i<temperatures.size();i++)
        {
            while (i+j<temperatures.size() && temperatures[i+j]<=temperatures[i]) //the future temp is not warmer than today
            {
                j++; //look further
                answer[i]++;
            }
            if (i+j==temperatures.size()) //if we never found a warmer day
                answer[i]=0;
            j=1;
        }
        return answer;
    }
};
//TC O(N^2)
//SC O(N)

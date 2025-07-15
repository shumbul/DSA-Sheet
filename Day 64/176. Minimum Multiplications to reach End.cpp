class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        unordered_set<int> visited;
        queue<int> values;
        int count=0;
        values.push(start);
        visited.insert(start);
        while (!values.empty())
        {
            int sizee=values.size();
            while (sizee--)
            {
            int frontt=values.front();
            if (frontt==end)
            {
                return count;
            }
            values.pop();
            for (int i:arr)
            {
                int newVal=(frontt*i)%100000; //multiplying the current number with each number in the array.
                if (visited.find(newVal)==visited.end())
                {
                    visited.insert(newVal);
                values.push(newVal);
                }
            }
            }
            count++; //we have processed all current level elements
        }
        return -1;
    }
};

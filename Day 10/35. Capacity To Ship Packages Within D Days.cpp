class Solution 
{
public:
    int shipWithinDays(vector<int>& weights, int days) 
    {
        int start=*max_element(weights.begin(), weights.end()); //ship must be able to carry at least the heaviest package
        int end=accumulate(weights.begin(), weights.end(), 0); //sum of all weights (if you do it in one day)
        int answer=end;
        bool ans=true;
        while (start<end)
        {
            int mid=start+(end-start)/2;
            ans=daysInMidCapacity(mid, days, weights); //can we ship all packages in days or less using capacity = mid?
            if (!ans) //capacity too small
                start=mid+1;
            else
            {
                answer=min(mid, answer); //enough capacity
                end=mid; //find smaller possible capacity
            }
        }
        return answer;
    }
    bool daysInMidCapacity (int capacity, int n, vector<int>& weights)
    {
        int days=1;
        int currCap=0; //total weight in current day
        for (auto w:weights)
        {
            if (currCap+w<=capacity)
            {
                currCap+=w;
            }
            else
            {
                days++; //start a new day
                currCap=w; //sart new day with current package 
                //currCap=0 would've skipped the current weight
            }
        }
        if (days<=n)
            return true;
        return false;
    }
};
//TC O(log(range)*n)
//SC O(1)

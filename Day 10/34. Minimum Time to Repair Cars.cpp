class Solution 
{
public:
    long long repairCars(vector<int>& ranks, int cars) 
    {
        bool ans=true;
        long long min_rank=*min_element(ranks.begin(), ranks.end());
        long long max_rank=*max_element(ranks.begin(), ranks.end());
        long long start=min_rank; //fastest mechanic fixing 1 car
        long long end=max_rank*cars*cars; //slowest mechanic fixing all cars
        long long answer=end;
        while (start<end)
        {
            long long mid=start+(end-start)/2;
            ans=carsRepairedInMidTime(mid, cars, ranks);
            if (ans)
            {
                answer=min(mid, answer); //update smaller answer
                end=mid; //find smaller possible answer
            }
            else
            {
                start=mid+1;
            }
        }
        return answer;
    }
    bool carsRepairedInMidTime(long long time, int cars, vector<int>& ranks)
    {
        long long carsInMidTime=0; //how many cars can be repaired by all mechanics within time
        for (int r:ranks)
        {
            carsInMidTime+=sqrt(time/r);
        }
        if (carsInMidTime>=cars) //if it can fix more than required cars in the given time, then it can fix required cars in the same time too
            return true;
        return false;
    }
};
//TC O(nlogn)
//SC O(1)

class Solution 
{
public:
    long long repairCars(vector<int>& ranks, int cars) 
    {
        bool ans = true;
        long long min_rank = *min_element(ranks.begin(), ranks.end());
        long long max_rank = *max_element(ranks.begin(), ranks.end());
        long long start = 1; //time starts from 1 unit, not rank
        long long end = max_rank * 1LL * cars * cars; //1LL prevents integer overflow during multiplication


        long long answer = end;
        while (start < end)
        {
            long long mid = start + (end - start) / 2;
            ans = carsRepairedInMidTime(mid, cars, ranks); //is mid time enough to repair cars using mechanics in ranks?
            if (ans)
            {
                answer = mid; //save this as potential answer
                end = mid; //find lower time
            }
            else
            {
                start = mid + 1;
            }
        }
        return answer;
    }
    bool carsRepairedInMidTime(long long time, int cars, vector<int>& ranks)
    {
        long long carsInMidTime = 0; //keeps count of total cars repaired in time mins
        for (int i = 0; i < ranks.size(); i++)
        {
            carsInMidTime += (long long)(sqrt(time / (double)ranks[i]));
            if (carsInMidTime >= cars) 
                return true; //if we've already repaired required number of cars, return true early
        }
        return carsInMidTime >= cars; //check if we reached or exceeded required no of cars
    }
};
//TC O(nlogn)
//SC O(1)

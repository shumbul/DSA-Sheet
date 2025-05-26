class Solution 
{
public:
    long long minDays(vector<int>& bloomDay, int m, int k) 
    {
        long long feasible=(long long)m*(long long)k;
        if (feasible>bloomDay.size())
            return -1;
        long long start=*min_element(bloomDay.begin(), bloomDay.end()); //we have to atleast that many days
        long long end=*max_element(bloomDay.begin(), bloomDay.end()); //when all flowers have bloomed
        long long answer=end;
        bool ans=true;
        while (start<end)
        {
            long long mid=start+(end-start)/2; //smallest days possible
            ans=helper(mid, m, k, bloomDay);
            if (ans)
            {
                answer=mid;
                end=mid;//find lesser waiting days
            }
            else
            {
                start=mid+1; //more days required
            }
        }
        return answer;
    }
    bool helper(long long days, int noofB, int FineachB, vector<int>& bloomDay)
    {
        long long count=0; //consequetive bloomed flowers
        long long totalB=0; //completed bouquets in given days
        for (long long i=0;i<bloomDay.size();i++)
        {
            if (bloomDay[i]<=days)
            {
                count++;
                if (count>=FineachB) //if we have required no. of flowers to make a bouquet
                {
                    totalB++;
                    count=0;    
                }
            }
            else
            {
                if (count>=FineachB)
                {
                    totalB++;
                }
                count=0; //consequetive flowers list broken, start again
                continue;
            }
        }
        if (totalB>=noofB) //if enough bouquets are made
            return true;
        return false;
    }
};

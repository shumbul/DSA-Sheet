// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution 
{
public:
    int firstBadVersion(int n) 
    {
        int start=1, end=n, mid=0;
        int ans=end;
        while (start<end)
        {
            mid=start+(end-start)/2;
            if (!isBadVersion(mid)) //if not bad then bad is in right
            {
                start=mid+1;
            }
            else
            {
                end=mid;
                ans=min(ans, end); //mid may get updated in next iteration
            }
        }
        return ans;
    }
};
//TC O(logn)
//SC O(1)

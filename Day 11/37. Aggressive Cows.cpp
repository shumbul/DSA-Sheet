//https://www.geeksforgeeks.org/problems/aggressive-cows/1

class Solution 
{
  public:

    int aggressiveCows(vector<int> &arr, int k) 
    {
        int n=arr.size();
        if (k>n)
		    return -1;
        sort(arr.begin(), arr.end());
        bool ans=true;
        int answer=0;
        int start=1; //min possible distance
        int end=arr[n-1]-arr[0]; //max possible distance
        while (start<=end)
        {
        	int mid=start+(end-start)/2; 
        	ans=canCowsGetPlaced(mid, n, k, arr);
        	if (ans)
        	{
        	    answer=mid; //distance is feasible
                start=mid+1; //try a larger distance
            }
            else
            {
        	    end=mid-1; //decrease distance
            }
        }
    	return end;
        
    }
    bool canCowsGetPlaced(int distance, int n, int k, vector<int> dist)
    {
    	int last=0; //index of the last stall where a cow was placed
    	int count=1; //no.of cows that can be placed, atleast 1 can be
        for (int i=1;i<dist.size();i++)
        {
        	if (dist[i]-dist[last]>=distance)
        	//if the current stall is at least distance away from the last placed cow, place a cow and update last
        	{
        	    count++;
        	    last=i;
        	}
        }
    	if (count>=k)
    		return true;
    	return false;
    }

};



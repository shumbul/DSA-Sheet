class Solution 
{
public:
    int minimizedMaximum(int n, vector<int>& quantities) 
    {
        if (n==quantities.size())
            return *max_element(quantities.begin(), quantities.end());
        int start=1; //a store must take atleast 1 item
        int end=*max_element(quantities.begin(), quantities.end()) //max a store can take max items of any product
        int answer=end;
        bool ans=true;
        while (start<end)
        {
            int mid=start+(end-start)/2;
            ans=helper(mid, n, quantities); //is it possible to distribute the items such that no store has more than mid items?
            if (!ans)
                start=mid+1;
            else
            {
                answer=min(mid, answer); //update best answer
                end=mid;  //find even smaller
            }
        }
        return answer;
    }
    bool helper (int capacity, int n, vector<int>& quantities)
    {
        int count=0;
        for (int i=0;i<quantities.size();i++)
        {
            count+=ceil((double)quantities[i]/capacity); //or each product type, calculate how many stores are needed if no store gets more than capacity items and add it to count
        }
        if (count<=n) //if you can distribute using n or less stores, it's valid
            return true;
        return false;
    }
};
//TC O(nlogn)
//SC O(1)

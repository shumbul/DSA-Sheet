class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num==1)
            return true;
        int start=1, end=num;
        while (start<end)
        {
            int mid=start+(end-start)/2;
            if (mid<num/mid) //mid*mid<num i.e. square root is in right
            {
                start=mid+1;
            }
            else if (mid>num/mid) //mid*mid>num i.e. square root is in left
            {
                end=mid;
            }
            else
            {
                if (mid*mid==num)
                    return true;
                else
                    return false;
            }  
        }
        return false;
    }
};
//TC O(logn)
//SC O(1)

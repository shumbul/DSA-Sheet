/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution 
{
public:
    int guessNumber(int n) 
    {
        int start=0, end=n, gues=0;
        while (start<=end)
        {
            int mid=start+(end-start)/2;
            gues=guess(mid);
            if (gues==-1) //target is smaller than mid
            {
                end=mid;
            }
            else if (gues==1) //target is larger than mid
            {
                start=mid+1;
            }
            else
                return mid;
        }
        return -1;
    }
};
//TC O(logn)
//SC O(1)

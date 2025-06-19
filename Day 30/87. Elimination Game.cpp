class Solution {
public:
    int lastRemaining(int n) {
        int diff=1; //step size between nos
        int no=n; //no of remaining elements
        int start=1; //curr 1st no in list
        bool left2right=true; //direction
        while (no>1)
        {
            if (left2right || no%2!=0)
                start+=diff;
            diff*=2;
            no/=2;
            left2right=!left2right;
        }
        return start;
    }
};
//TC O(logn)
//SC O(1)

class Solution {
public:
    int lastRemaining(int n) {
        int diff=1, no=n, start=1;
        bool left2right=true;
        return helper(diff, n, start, left2right);
    }
    int helper (int diff, int no, int start, bool left2right)
    {
        if (no==1)
        {
            return start;
        }
        if (left2right || no%2!=0)
                start+=diff;
            diff*=2;
            no/=2;
            left2right=!left2right;
        return helper(diff, no, start, left2right);
    }
};

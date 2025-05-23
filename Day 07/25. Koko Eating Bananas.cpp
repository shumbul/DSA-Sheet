class Solution {
    bool isValid(int speed, int h, vector<int> piles)
    //Checks if Koko can eat all bananas at a given speed within h hours
    {
        int hours=0;
        for(int &p:piles){
            hours+=ceil((double)p/speed); //hours needed for current pile is added to total
            //ceil takes lower rounded up
            //double ensures floating-point division, so fractional hours aren’t lost. 
        }
        return (hours<=h); //returns true if it can eat in this speed
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int start=1; //min speed i.e. atleast 1 banana in 1hr
        int end=*max_element(piles.begin(), piles.end()); //max speed i.e. largest pile is eaten in 1hr
        int ans=end;
        while (start<end)
        {
            int mid=(start+end)/2;
            if (isValid(mid, h, piles))
            {
                end=mid; //try slower speed
                ans=min(ans, mid); //update slowest speed
            }
            else
            {
                start=mid+1; //try faster speed
            }
        }
        return ans;
    }
};
//3, 5, 1, 5, 2, 5, 5, 1

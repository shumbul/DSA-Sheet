class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> ugly(n); //store the first n ugly numbers
        ugly[0] = 1; // first ugly number is always 1 
        int i2 = 0, i3 = 0, i5 = 0; //track indices of the last used multiples of 2, 3, and 5 initially it is 1 i.e. 0 index
        for (int i = 1; i < n; i++) {
            int next2 = ugly[i2] * 2;
            int next3 = ugly[i3] * 3;
            int next5 = ugly[i5] * 5;
            int next = min({next2, next3, next5}); //This ensures sorted order
            ugly[i] = next; //Store this next ugly number in the array at index i
          //Advance the pointers for which the current minimum value was used
            if (next == next2) 
                i2++;
            if (next == next3) 
                i3++;
            if (next == next5) 
                i5++;
        }
        return ugly[n - 1];
    }
};
//TC O(N)
//SC O(N)

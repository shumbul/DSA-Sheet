class Solution {
public:
    int hammingDistance(int x, int y) {
        x=x^y;
        int count=0;
        while (x)
        {
            count+=x&1; //checks if rightmost bit is 1
            x=x>>1; //Right shift x by 1 bit to check the next bit in the next iteration.
        }
        return count;
    }
};

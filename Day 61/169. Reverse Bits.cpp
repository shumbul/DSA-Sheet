class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans=0;
        int k=32;
        while (k--)
        {
            ans=ans<<1 | (n&1); //ans ke right side me add new value, which will be decided by n&1. if n&1 is 1, then append 1 else append 0. n&1 gives last bit of n
            n=n>>1; //n ka last bit hata dia
        }
        return ans;
    }
};

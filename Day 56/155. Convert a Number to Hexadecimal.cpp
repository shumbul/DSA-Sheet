class Solution {
public:
    string toHex(int num) {
        int ans=0; //temporary variable to hold the value of each 4-bit group.
        string hexans="";
        if (num<0)
        {
            num=abs(num);
            num=(~num)+1; //2's complement
        }
        while (num)
        {
            ans=0;
            for (int i=0;i<4;i++)
            {
            ans=ans<<1 | (num&1); //extracts the least significant bit and builds the binary number by shifting and adding bits.
            num=num>>1;
            }
            if (ans<=9)
            hexans+=to_string(ans);
            else
            hexans+='a'+(ans-10);
        }
        return hexans;
    }
};

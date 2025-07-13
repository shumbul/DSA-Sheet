class Solution {
public:
    int findComplement(int num) {
        if (num == 0) 
          return 1;
        int mask = 0;
        int temp = num;
        // Create a mask with the same number of bits as num, all set to 1
        while (temp) {
            mask = (mask << 1) | 1; //shifts all bits left and sets the new last bit to 1
            temp =temp>> 1; // keep adding a 1-bit on the right until we match the number of bits in num
        }
        // XOR flips only the bits that matter
        return num ^ mask;
    }
};

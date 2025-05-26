class Solution 
{
public:
    int countDigits(int num) 
    {
        unordered_map<int, int> freq;
        int count=0;
        int original=num;
        int digit=0;
        int length=(num==0)?1:(int)log10(abs(num))+1; //int removes decimal part
        for (int i=0;i<length;i++)
        {
            digit=num%10;
            freq[digit]++;
            num=num/10;
        }
        for (auto val:freq)
        {
            if (original%val.first==0)
            {
                count+=val.second;
            }
        }
        return count;
    }
};

//TC O(N)
//SC O(1)

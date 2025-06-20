class Solution {
public:
    bool sumGame(string num) {
        int sum1=0; //sum of known digits in 1st half
        int sum2=0; //sum of known digits in 2nd half
        int count1=0; //no of ? in 1st half
        int count2=0; //no of ? in 2nd half
        string first=num.substr(0, num.size()/2);
        string second=num.substr(num.size()/2, num.size()/2);
        for (int i=0;i<first.size();i++)
        {
            if (first[i]!='?')
                sum1+=first[i]-'0';
             if (second[i]!='?')
                sum2+=second[i]-'0';
            if (first[i]=='?') 
                count1++;
            if (second[i]=='?')
                count2++;
        }
        if (count1+count2==0)
            return (sum1!=sum2);
        if ((count1+count2)%2!=0) //? is odd, alice makes the last move, she can always win.
            return true;
        else
        {
            int ans=sum1-sum2+(count1/2)*9-(count2/2)*9; //alice will try to maximise sum and bob will try to balance sum
            if (ans!=0)
                return true;
            else
                return false;
        }
        return (sum1==sum2);
    }
};

class Solution {
public:
    char findTheDifference(string s, string t) {
        char ans=0;
        for (int i=0;i<t.size();i++)
        {
            ans=ans^s[i]^t[i];
        }
        return ans;
    }
};

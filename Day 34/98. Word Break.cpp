class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        if (n==0)
            return true;
        for (int i=1;i<=n;i++)
        {
            if (find(wordDict.begin(), wordDict.end(), s.substr(0, i))!=wordDict.end())
            //s.substr(0, i) gives a prefix to check
            //if the prefix exists in the dict then it's a valid word
            {
                if (wordBreak(s.substr(i), wordDict))
                //remaining string
                    return true;
            }
        }
        return false;
    }
};
//TC O(2^N)
//SC O(1)

class Solution {
    vector<bool> dp;
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        dp.resize(s.size()+1, false);
        dp[0]=true;
        for (int i=1;i<=s.size();i++)
        {
            for (int j=0;j<=i;j++)
            {
                if (dp[j] && find(wordDict.begin(), wordDict.end(), s.substr(j, i-j))!=wordDict.end()) //word [j to i-1]
                {
                    dp[i]=true; //s[0to i-1] can be segmented
                    break; //no need to check more partitions for this i
                }
            }
        }
        return dp[s.size()];
    }
};
//TC O(N^2)
//SC O(N)

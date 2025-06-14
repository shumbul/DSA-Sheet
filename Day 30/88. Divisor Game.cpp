class Solution {
public:
    bool divisorGame(int n) {
        return (n%2==0);
    }
};

class Solution {
public:
    bool divisorGame(int n) {
        vector<bool> dp(n+1, false); //can Alice win when the n is i
        dp[0]=true;
        dp[1]=false; //alice cant make a move
        for (int i=2;i<=n;i++)
        {
            for (int j=1;j<i;j++)
            {
                if (i%j==0 && dp[i-j]==false)
                {//j is valid  && possibility of bob to win
                //after Alice removes j, Bob is left with i - j, and if he cant win, then Alice can win now
                    dp[i]=true;
                }
            }
        }
        return dp[n];
    }
};
//TC O(n^2)
//SC O(n)

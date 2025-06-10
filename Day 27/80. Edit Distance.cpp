class Solution {
    vector<vector<int>> dp;
public:
    int minDistance(string word1, string word2) {
        dp.resize(word1.size()+1, vector<int> (word2.size()+1, -1));
        //dp[i][j] means min operations required to convert word1[i:] to word2[j:]
        return helper(word1, word2, 0, 0);
    }
    int helper(string word1, string word2, int pos1, int pos2) {
        //tries to transform word1[pos1:] into word2[pos2:]
            if (pos2==word2.size())
                return (word1.size()-pos1); //delete remaining chars in word1
            if (pos1==word1.size())
                return (word2.size()-pos2); //insert remaining chars from word2
        int rep = 0, del = 0, add = 0;
        if (dp[pos1][pos2]!=-1)
            return dp[pos1][pos2];
        if (word1[pos1] != word2[pos2]) {
            del = helper(word1, word2, pos1 + 1, pos2);
            add = helper(word1, word2, pos1, pos2 + 1);
            rep = helper(word1, word2, pos1 + 1, pos2 + 1);
        } else {
            return dp[pos1][pos2]=helper(word1, word2, pos1 + 1, pos2 + 1);
        }
        return dp[pos1][pos2]=min({add, rep, del}) + 1; //store and return min operations among the three possible ones, +1 for current step
    }
};
//TC O(M*N)
//SC O(M*N)

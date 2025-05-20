class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) 
    {
        vector<string> ans;
        for (int i = 0; i < words.size(); i++) 
        {
            int count = 0;
            map<char, char> match;
            map<char, char> check;
            for (int j = 0; j < words[i].size(); j++) 
            {
                if (match.count(pattern[j])>0 || check.count(words[i][j])>0)
                //if letter of words or letter of pattern already exists in the map
                {
                    if (match[pattern[j]] != words[i][j])
                        break;
                    //pattern->word and word->pattern should be same
                    if (check[words[i][j]]!=pattern[j])
                        break;
                }
                match[pattern[j]]=words[i][j];
                check[words[i][j]]=pattern[j];
                count++;
            }
            if (count == pattern.size()) 
            //push the word only if it is size of pattern i.e. the word is completely traversed
            {
                ans.push_back(words[i]);
                count = 0; //for next word
            }
        }
    return ans;
    }
};
//TC O(N^2)
//SC O(N)

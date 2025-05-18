class Solution 
{
public:
    string reverseWords(string s) 
    {
        vector<string> words;
        string word="";
        string ans="";
        for (int i=0;i<s.size();i++)
        {
            if (isalnum(s[i]))
            {
                word=word+s[i];
                if (i==s.size()-1)
                //reached last letter of string
                {
                    words.push_back(word);
                }
            }
            else
            {
                if (word.size()!=0)
                {
                    words.push_back(word);
                    //break the string and push the word formed
                }
                word="";
                //new word
            }
        }
        reverse(words.begin(), words.end());
        for (int i=0;i<words.size();i++)
        {
            ans=ans+words[i];
            if (i!=words.size()-1)
                ans=ans+" ";
          //add spaces till end of string
        }
        return ans;
    }
};
//TC O(N)
//SC O(N)

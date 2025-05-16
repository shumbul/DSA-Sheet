class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) 
    {
        string ans="";
        for (int i=0;i<words.size();i++)
        {
            if (ans!=s)
            ans=ans+words[i];
            else
                return true;
        }
        if (ans==s)
            return true;
      //check again when s ends
        return false;
    }
};
//TC O(N)
//SC O(N)

class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) 
    {
        string ans="";
        for (int i=0;i<words.size();i++)
        {
            ans=ans+words[i];
          //no need to check, keep adding till if case is true
            if (ans==s)
                return true;
        }
        return false;
    }
};
//TC O(N)
//SC O(N)

class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) 
    {
        string ans="";
        for (string word:words)
          //range based for loop
        {
            ans=ans+word;
            if (ans==s)
                return true;
        }
        return false;
    }
};
//TC O(N)
//SC O(N)

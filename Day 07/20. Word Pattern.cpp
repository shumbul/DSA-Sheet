class Solution 
{
public:
    bool wordPattern(string pattern, string s) 
    {
        vector<string> s1;
        vector<string> s2;
        //store pattern and s in vectors
        string word ="";
        for (int i = 0; i < pattern.size(); i++) 
        {
            s1.push_back(to_string(pattern[i]));
        }
        for (int i=0;i<s.size();i++)
        {
            if (isalnum(s[i]))
	        {
                word += s[i];
                //create word
                if (i == s.size() - 1)
                    s2.push_back(word);
	        }
	        else
            //when space comes, break word and push in vector
	        {
                s2.push_back(word);
                word ="";
	        }
        }
        if (s1.size()!=s2.size())
        {   
	        return false;
        }
        unordered_map<string, string> check;
        //to map s->pattern
        unordered_map<string, string> comb;
        //to map pattern->s
        for (int i=0;i<s1.size();i++)
        {
            if (comb.count(s1[i]) > 0 || check.count(s2[i])>0) 
            //if pattern or s is already in map
            {
                if (comb[s1[i]] != s2[i])
                    return false;
                if (check[s2[i]]!=s1[i])
                    return false;
                //pattern->s and s->pattern should be same
            }
            comb[s1[i]] = s2[i];
            check[s2[i]]=s1[i];
        }
        return true;
    }
};
//TC O(N)
//SC O(N)

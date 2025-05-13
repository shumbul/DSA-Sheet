class Solution 
{
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        unordered_map<string, vector<string>> words;
        vector<vector<string>> ans;
        for (int i=0;i<strs.size();i++)
        {
            string temp=strs[i];
            sort(temp.begin(), temp.end());
            //words[temp] is words ka value i.e. vector<string> so push back
            words[temp].push_back(strs[i]);
        }
        for (auto value:words)
        //& will give the value of the address
        //traverse map
        {
            auto val=value.second;
            //we used map<vector> so we are explicitly traversing the values, map<int> me sirf keys traverse karte
            ans.push_back(val);
        }
        return ans;
    }
    //l is longest length of string in strs
    //llogl is for sorting
    //TC=O(n*llogl)
    //n words are stored, worst case me 1 key will have value as all elements in strs, so size of value will be entire size of strs
    //SC=O(n*m)
    //m is sum of all elements in strs
};
//map:
//key(string)->value(vector<string>)
//aet->eat,tea,ate
//comparing word by word and letter by letter is not feasible as it can only work on 2 words, not more

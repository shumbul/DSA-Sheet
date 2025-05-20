// https://leetcode.com/problems/find-all-anagrams-in-a-string/

class Solution {
    map<char, int> pattern, subs;
    bool handle_first_pattern(string s, int size){
        for (int i = 0; i < size; i++) {
            if (pattern[s[i]] != subs[s[i]])
                return false;
        }
        return true;
    }
public:
    vector<int> findAnagrams(string s, string p) {
        if (p.size() > s.size())
            return {};
        
        vector<int> ans;
        string substring = "";

        for (int i = 0; i < p.size(); i++) {
            pattern[p[i]]++;
            subs[s[i]]++;
        }

        if(handle_first_pattern(s, p.size()))
            ans.push_back(0);

        for (int i = 1; i < s.size() - p.size() + 1; i++) {
            subs[s[i - 1]]--;
            subs[s[i + p.size() - 1]]++;
            int j=0;
            for (j = 0; j < p.size(); j++) {
                char curr = s[i + j];
                if (pattern[curr] != subs[curr]) {
                    break;
                }
            }
            if (j == p.size()) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};

// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/

class Solution {
public:
    int strStr(string haystack, string needle) {
        for(int i=0;i<haystack.size();i++){
            if(haystack[i]==needle[0]){
                // find for complete needle string
                // cout<<haystack.substr(i, i+needle.size())<<" ";
                if(haystack.substr(i, needle.size())==needle){
                    return i;
                }
            }
        }
        return -1;
        // TC: O(n^2), SC: O(1)
    }
};


class Solution {
    bool helper(string haystack, int idx, string needle){
        for(int j=0;j<needle.size();j++){
            if(haystack[j+idx]!=needle[j])
                return false;
        }
        return true;
    }
public:
    int strStr(string haystack, string needle) {
        for(int i=0;i<haystack.size();i++){
            if(haystack[i]==needle[0]){
                // find for complete needle string
                bool same = helper(haystack, i, needle);
                if(same) return i;
            }
        }
        return -1;
        // TC: O(n^2), SC: O(1)
    }
};

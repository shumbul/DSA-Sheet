class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        int maxLen = 0; //to keep track of the max length of a valid window
        int j=0; //start index of window
         int maxFreq = 0; //to store the count of the most frequent char in window. This is used to decide how many replacements are needed
          vector<int> count(26, 0);
        for (int i = 0; i < n; i++) {
            count[s[i] - 'A']++;
            maxFreq=*max_element(count.begin(), count.end()); //this helps us know how many chars we need to change to make all chars same in the window
            while ((i-j+1)-maxFreq>k)
            //window size-no of chars already same
            {   //shrink window
                count[s[j]-'A']--;
                j++;
                maxFreq=*max_element(count.begin(), count.end());
            }
            maxLen=max(maxLen, i-j+1); //update max window
        }
        return maxLen;
    }
};
//TC O(n)
//SC O(1)

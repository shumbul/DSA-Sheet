class Solution 
{
public:
    int lengthOfLongestSubstring(string s) 
    {
        unordered_set<char> letters;
        int left=0;
        //left pointer for sliding window
        int max_len=0;
        //stores length
        for (int right=0;right<s.size();right++)
        //right pointer traversal
        {
            while (letters.count(s[right]))
            //if right letter is already in set
            {
                letters.erase(s[left]);
                //remove left letter
                left++;
                //reduce window
            }
            letters.insert(s[right]);
            //add the new letter in set
            max_len=max(max_len, right-left+1);
            //update length accordingly
        }
        return max_len;
    }
};
//TC O(N)
//SC O(N)

class Solution 
{
public:
    int lengthOfLongestSubstring(string s) 
    {
        unordered_map<char, int> last_occurrence;
        int left = 0, max_len = 0;
        for (int right = 0; right < s.length(); right++) 
        {
            if (last_occurrence.count(s[right])) 
            {
                left = max(left, last_occurrence[s[right]] + 1); // Jump `left`
            }
            last_occurrence[s[right]] = right; // Update last occurrence
            max_len = max(max_len, right - left + 1); // Update max
        }
        return max_len;
    }
};
//TC O(N)
//SC O(N)

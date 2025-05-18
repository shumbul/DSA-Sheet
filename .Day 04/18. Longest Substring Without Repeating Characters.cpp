class Solution 
{
public:
    int lengthOfLongestSubstring(string s) 
    {
        unordered_set<char> chars;
        int left = 0, max_len = 0;
        for (int right = 0; right < s.length(); right++) 
        {
            while (chars.count(s[right])) 
            { // If duplicate found
                chars.erase(s[left]);      // Remove from set
                left++;                    // Move left forward
            }
            chars.insert(s[right]);        // Add new char to set
            max_len = max(max_len, right - left + 1); // Update max
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

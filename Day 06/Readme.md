## 📘 Notes – Palindromes & Pattern Substrings

---

### ✅ 1. Longest Palindromic Substring

🔗 [Problem Link](https://leetcode.com/problems/longest-palindromic-substring/)
🧠 **Topic**: Dynamic Programming / Two Pointers

#### 📌 Problem

Given a string `s`, return the longest palindromic substring in `s`.

#### 🧠 Key Idea

A **palindrome** reads the same forward and backward.
We expand from the center of each index and track the max-length palindrome.

#### ✅ Code (Expand Around Center Approach)

```cpp
string longestPalindrome(string s) {
    if (s.empty()) return "";

    int start = 0, end = 0;

    for (int i = 0; i < s.length(); i++) {
        int len1 = expandAroundCenter(s, i, i);     // odd length
        int len2 = expandAroundCenter(s, i, i + 1); // even length
        int len = max(len1, len2);

        if (len > end - start) {
            start = i - (len - 1) / 2;
            end = i + len / 2;
        }
    }

    return s.substr(start, end - start + 1);
}

int expandAroundCenter(string s, int left, int right) {
    while (left >= 0 && right < s.length() && s[left] == s[right]) {
        left--;
        right++;
    }
    return right - left - 1;
}
```

🔎 **Functions Highlighted**:

* `expandAroundCenter`: helper function to reuse logic for odd/even palindrome expansion.

---

### ✅ 2. Find Longest Special Substring That Occurs Thrice I

🔗 [Problem Link](https://leetcode.com/problems/find-longest-special-substring-that-occurs-thrice-i/)
🧠 **Topic**: HashMap, Substring Frequency, Sliding Window (variable size)

#### 📌 Problem

Return the **length of the longest substring** that occurs **at least 3 times** in a string.

#### 🧠 Key Idea

Use a **helper function** to check if a substring of length `k` occurs at least 3 times.
Apply **Binary Search** on length from 1 to `s.size()`.

#### ✅ Code (Binary Search + HashMap + Function)

```cpp
bool hasSubstringOccurringThrice(string& s, int len) {
    unordered_map<string, int> freq;

    for (int i = 0; i <= s.size() - len; i++) {
        string sub = s.substr(i, len);
        if (++freq[sub] == 3) return true;
    }

    return false;
}

int maximumLength(string s) {
    int left = 1, right = s.length(), ans = 0;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (hasSubstringOccurringThrice(s, mid)) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return ans;
}
```

🔎 **Functions Highlighted**:

* `hasSubstringOccurringThrice`: clean helper function to check if any substring of a given length appears ≥ 3 times.

---

## 🧩 Pattern Note: Functions + Substring Frequency

---

### 📌 Why Use Functions?

Using functions like `expandAroundCenter` or `hasSubstringOccurringThrice` helps:

* Encapsulate logic for readability & reuse
* Avoid repetitive code inside loops
* Improve debugging & testability

---

### 🧠 Where It Helps

| Use Case                                 | Function Purpose                        |
| ---------------------------------------- | --------------------------------------- |
| Expand from center for palindromes       | Modular handling of both odd/even cases |
| Check substring frequency for length `k` | Used in sliding window / binary search  |
| Count/match frequency of characters      | Anagram, unique character problems      |

---

## 📘 Notes – Selected LeetCode Questions for Revision

---

### ✅ 3. Group Anagrams

🔗 [Problem Link](https://leetcode.com/problems/group-anagrams/)
🧠 **Topic**: HashMap, String Manipulation

#### 📌 Problem

Group strings that are anagrams of each other.

#### 🧠 Key Idea

Sort each string – anagrams share the same sorted form.
Use a `HashMap` where key = sorted string, value = list of anagrams.

#### ✅ Code

```cpp
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> mp;

    for (string s : strs) {
        string sortedStr = s;
        sort(sortedStr.begin(), sortedStr.end());
        mp[sortedStr].push_back(s);
    }

    vector<vector<string>> result;
    for (auto& pair : mp) {
        result.push_back(pair.second);
    }

    return result;
}
```

---

### ✅ 4. Valid Parentheses

🔗 [Problem Link](https://leetcode.com/problems/valid-parentheses/)
🧠 **Topic**: Stack

#### 📌 Problem

Check if the input string has valid parentheses pairing.

#### 🧠 Key Idea

Use a stack to match open and closing brackets.

#### ✅ Code

```cpp
bool isValid(string s) {
    stack<char> st;

    for (char c : s) {
        if (c == '(' || c == '{' || c == '[')
            st.push(c);
        else {
            if (st.empty()) return false;
            if ((c == ')' && st.top() != '(') ||
                (c == '}' && st.top() != '{') ||
                (c == ']' && st.top() != '['))
                return false;
            st.pop();
        }
    }

    return st.empty();
}
```

---

### ✅ 5. Check if All Characters Have Equal Number of Occurrences

🔗 [Problem Link](https://leetcode.com/problems/check-if-all-characters-have-equal-number-of-occurrences)
🧠 **Topic**: HashMap

#### 📌 Problem

Return true if all characters occur the same number of times.

#### ✅ Code

```cpp
bool areOccurrencesEqual(string s) {
    unordered_map<char, int> freq;
    for (char c : s) freq[c]++;

    int count = freq.begin()->second;
    for (auto& pair : freq)
        if (pair.second != count) return false;

    return true;
}
```

---

### ✅ 6. Find the Index of the First Occurrence in a String

🔗 [Problem Link](https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string)
🧠 **Topic**: Substring Matching

#### 📌 Problem

Return the index of the first occurrence of `needle` in `haystack`.

#### ✅ Code

```cpp
int strStr(string haystack, string needle) {
    return haystack.find(needle); // Built-in
}
```

> You could also implement KMP or a naive loop if needed for interview.

---

### ✅ 7. Longest Palindrome

🔗 [Problem Link](https://leetcode.com/problems/longest-palindrome)
🧠 **Topic**: HashMap, Greedy

#### 📌 Problem

Build the longest palindrome using the letters of a given string.

#### 🧠 Key Idea

Use even counts fully, add one odd in the center if available.

#### ✅ Code

```cpp
int longestPalindrome(string s) {
    unordered_map<char, int> freq;
    for (char c : s) freq[c]++;

    int length = 0;
    bool oddFound = false;

    for (auto& p : freq) {
        length += (p.second / 2) * 2;
        if (p.second % 2 == 1) oddFound = true;
    }

    return length + (oddFound ? 1 : 0);
}
```

---

### ✅ 8. Permutation in String

🔗 [Problem Link](https://leetcode.com/problems/permutation-in-string)
🧠 **Topic**: Sliding Window, HashMap

#### 📌 Problem

Check if `s2` contains a permutation of `s1`.

#### 🧠 Key Idea

Use sliding window of size `s1.length()`. Compare frequency maps.

#### ✅ Code

```cpp
bool checkInclusion(string s1, string s2) {
    if (s1.length() > s2.length()) return false;

    vector<int> s1map(26, 0), s2map(26, 0);

    for (int i = 0; i < s1.length(); i++) {
        s1map[s1[i] - 'a']++;
        s2map[s2[i] - 'a']++;
    }

    if (s1map == s2map) return true;

    for (int i = s1.length(); i < s2.length(); i++) {
        s2map[s2[i] - 'a']++;
        s2map[s2[i - s1.length()] - 'a']--;
        if (s1map == s2map) return true;
    }

    return false;
}
```

---

### ✅ 9. Longest Substring Without Repeating Characters

🔗 [Problem Link](https://leetcode.com/problems/longest-substring-without-repeating-characters)
🧠 **Topic**: Sliding Window (Variable size), HashMap

#### 📌 Problem

Find the length of the longest substring with all unique characters.

#### ✅ Code

```cpp
int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> mp;
    int left = 0, maxLen = 0;

    for (int right = 0; right < s.length(); right++) {
        mp[s[right]]++;

        while (mp[s[right]] > 1) {
            mp[s[left]]--;
            left++;
        }

        maxLen = max(maxLen, right - left + 1);
    }

    return maxLen;
}
```

---

## 📅 Revision Table

| No. | Question                                                 | Difficulty | Needs Revisit? | Link                                                                                               |
| --- | -------------------------------------------------------- | ---------- | -------------- | -------------------------------------------------------------------------------------------------- |
| 1   | Longest Palindromic Substring                            | Medium     | ✅              | [LeetCode](https://leetcode.com/problems/longest-palindromic-substring)                            |
| 2   | Find Longest Special Substring That Occurs Thrice I      | Medium     | ✅              | [LeetCode](https://leetcode.com/problems/find-longest-special-substring-that-occurs-thrice-i/)     |
| 3   | Group Anagrams                                           | Medium     | ✅              | [LeetCode](https://leetcode.com/problems/group-anagrams)                                           |
| 4   | Valid Parentheses                                        | Easy       | ⏳              | [LeetCode](https://leetcode.com/problems/valid-parentheses)                                        |
| 5   | Check If All Characters Have Equal Number of Occurrences | Easy       | ❌              | [LeetCode](https://leetcode.com/problems/check-if-all-characters-have-equal-number-of-occurrences) |
| 6   | Find the Index of the First Occurrence in a String       | Easy       | ❌              | [LeetCode](https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string)       |
| 7   | Longest Palindrome                                       | Easy       | ✅              | [LeetCode](https://leetcode.com/problems/longest-palindrome)                                       |
| 8   | Permutation in String                                    | Medium     | ✅              | [LeetCode](https://leetcode.com/problems/permutation-in-string)                                    |
| 9   | Longest Substring Without Repeating Characters           | Medium     | 🔁             | [LeetCode](https://leetcode.com/problems/longest-substring-without-repeating-characters)           |

---

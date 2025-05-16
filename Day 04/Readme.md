## 🚪 Sliding Window Technique

---

### 📌 What is Sliding Window?

Sliding Window is an optimization technique used for problems dealing with **contiguous subarrays or substrings**. It involves a window that moves through the data to reduce unnecessary re-computation.

---

### 🧠 When to Use

- Problems asking for **maximum/minimum/sum/average** of subarrays/substrings  
- **Pattern matching**, frequency count  
- **Longest/shortest subarray** with a certain property

---

### 🔸 Types of Sliding Window

| Type             | Window Size     | Common Use Case                                |
|------------------|------------------|-------------------------------------------------|
| Fixed Window     | Constant size    | Max sum of k elements, averages, etc.           |
| Variable Window  | Dynamic size     | Longest substring with unique/restricted chars |

---

### ✅ Fixed Size Sliding Window

**Problem**: Maximum sum of subarray of size `k`

```
int maxSum(vector<int>& nums, int k) {
    int windowSum = 0, maxSum = 0;

    for (int i = 0; i < k; i++)
        windowSum += nums[i];
    
    maxSum = windowSum;

    for (int i = k; i < nums.size(); i++) {
        windowSum += nums[i] - nums[i - k];
        maxSum = max(maxSum, windowSum);
    }

    return maxSum;
}
````

🧩 **Use-case**: Finding the max average temperature in any `k` consecutive days.

---

### ✅ Variable Size Sliding Window

**Problem**: Longest substring without repeating characters

```
int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> freq;
    int left = 0, maxLen = 0;

    for (int right = 0; right < s.size(); right++) {
        freq[s[right]]++;

        while (freq[s[right]] > 1) {
            freq[s[left]]--;
            left++;
        }

        maxLen = max(maxLen, right - left + 1);
    }

    return maxLen;
}
```

🧩 **Use-case**: Password validation – check for uniqueness in substrings.

---

## 🎯 Two Pointers Technique

---

### 📌 What is Two Pointers?

Two Pointers is a pattern used to solve problems involving **sorted arrays or linked lists** by maintaining two indices and moving them based on some condition.

---

### 🧠 When to Use

* Pair sum problems (like Two Sum)
* Reversing arrays in-place
* Detecting palindromes
* Merging sorted arrays
* Removing duplicates

---

### ✅ Example 1: Two Sum (Sorted Array)

```
bool hasTwoSum(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;

    while (left < right) {
        int sum = nums[left] + nums[right];
        if (sum == target)
            return true;
        else if (sum < target)
            left++;
        else
            right--;
    }

    return false;
}
```

🧩 **Use-case**: Can you buy 2 items with a gift card?

---

### ✅ Example 2: Is Palindrome

```
bool isPalindrome(string s) {
    int left = 0, right = s.length() - 1;

    while (left < right) {
        if (!isalnum(s[left])) left++;
        else if (!isalnum(s[right])) right--;
        else if (tolower(s[left]) != tolower(s[right])) return false;
        else {
            left++;
            right--;
        }
    }

    return true;
}
```

🧩 **Use-case**: User input validation – check if a string reads the same forward and backward.

---

### ✅ Example 3: Merge Two Sorted Arrays

```
vector<int> mergeSorted(vector<int>& a, vector<int>& b) {
    int i = 0, j = 0;
    vector<int> merged;

    while (i < a.size() && j < b.size()) {
        if (a[i] < b[j]) merged.push_back(a[i++]);
        else merged.push_back(b[j++]);
    }

    while (i < a.size()) merged.push_back(a[i++]);
    while (j < b.size()) merged.push_back(b[j++]);

    return merged;
}
```

🧩 **Use-case**: Merging timelines sorted by timestamps.

---

### 📝 Summary

| Technique      | When to Use                               | Time Complexity |
| -------------- | ----------------------------------------- | --------------- |
| Sliding Window | Contiguous elements, sums, substrings     | O(n)            |
| Two Pointers   | Sorted arrays, palindromes, merging, etc. | O(n)            |

- 💡 Use **Sliding Window** when the focus is on a **range/interval**
- 💡 Use **Two Pointers** when dealing with **comparison from two ends or merging**

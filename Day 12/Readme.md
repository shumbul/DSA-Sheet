# 🔗 Notes on `unordered_map`, `set`, and `multimap` in C++

---

## 📌 1. Overview

| Data Structure  | Key Uniqueness | Maintains Order | Allows Duplicate Keys | Underlying Structure |
| --------------- | -------------- | --------------- | --------------------- | -------------------- |
| `unordered_map` | ✅ Yes          | ❌ No            | ❌ No                  | Hash Table           |
| `set`           | ✅ Yes          | ✅ Yes (sorted)  | ❌ No                  | Red-Black Tree (BST) |
| `multimap`      | ❌ No           | ✅ Yes (sorted)  | ✅ Yes                 | Red-Black Tree (BST) |

---

## ⏱️ 2. Time Complexity

| Operation  | `unordered_map`       | `set` / `map` | `multimap` |
| ---------- | --------------------- | ------------- | ---------- |
| Insert     | O(1) avg / O(n) worst | O(log n)      | O(log n)   |
| Search     | O(1) avg / O(n) worst | O(log n)      | O(log n)   |
| Erase      | O(1) avg / O(n) worst | O(log n)      | O(log n)   |
| Count/Find | O(1)                  | O(log n)      | O(log n)   |

> ✅ `unordered_map` is faster **on average** but does **not maintain order**. Use `map` or `set` when ordering is needed.

---

## 🔍 3. Syntax & Usage

### 🧠 `unordered_map` Example

```cpp
unordered_map<int, string> mp;
mp[1] = "one";
mp[2] = "two";

// Access
if (mp.count(2)) cout << mp[2];

// Traverse
for (auto& p : mp)
    cout << p.first << " -> " << p.second << endl;
```

### 🧠 `set` Example

```cpp
set<int> s;
s.insert(10);
s.insert(5);
s.insert(10);  // Duplicates ignored

for (int val : s)
    cout << val << " ";  // Output: 5 10
```

### 🧠 `multimap` Example

```cpp
multimap<int, string> mm;
mm.insert({1, "A"});
mm.insert({1, "B"});
mm.insert({2, "C"});

// Iterate
for (auto& p : mm)
    cout << p.first << " -> " << p.second << endl;

// Count occurrences
cout << mm.count(1);  // Output: 2

// Get range of values with same key
auto range = mm.equal_range(1);
for (auto it = range.first; it != range.second; ++it)
    cout << it->second << " ";  // Output: A B
```

---

## ⚠️ 4. Common Pitfalls

* `unordered_map` doesn’t guarantee order; don’t use it when order matters.
* Avoid modifying keys in `set` or `map` after insertion — undefined behavior.
* In `multimap`, use `equal_range()` to safely access multiple entries of the same key.
* `unordered_map` has O(n) worst case due to hash collisions.

---

## 🧪 5. When to Use What?

| Use Case                                   | Suggested DS            |
| ------------------------------------------ | ----------------------- |
| Count frequencies                          | `unordered_map` / `map` |
| Store unique sorted values                 | `set`                   |
| Store duplicate keys with sorted ordering  | `multimap`              |
| Fast lookups (non-sorted)                  | `unordered_map`         |
| Custom comparator or order-based traversal | `set` / `map`           |

---

## 📘 Practice Problems

### 🔹 For `unordered_map` / `map`

* [Two Sum](https://leetcode.com/problems/two-sum/)
* [Group Anagrams](https://leetcode.com/problems/group-anagrams/)
* [Top K Frequent Elements](https://leetcode.com/problems/top-k-frequent-elements/)
* [Longest Consecutive Sequence](https://leetcode.com/problems/longest-consecutive-sequence/)

### 🔹 For `set`

* [Intersection of Two Arrays](https://leetcode.com/problems/intersection-of-two-arrays/)
* [Contains Duplicate](https://leetcode.com/problems/contains-duplicate/)
* [Sliding Window Median](https://leetcode.com/problems/sliding-window-median/)

### 🔹 For `multimap` (less common but useful in interviews)

* [Reorder Log Files](https://leetcode.com/problems/reorder-data-in-log-files/) *(custom sorting)*
* [Sort Characters by Frequency](https://leetcode.com/problems/sort-characters-by-frequency/)
* [Design a Leaderboard](https://leetcode.com/problems/design-a-leaderboard/) *(can be solved with multimap for scores)*

---

## 📚 Glossary

* 🔹 **Hash Table**: Stores key-value pairs with fast average-time lookup.
* 🔹 **Red-Black Tree**: A self-balancing BST used by `map`, `set`, `multimap`.
* 🔹 **Multimap**: Like `map`, but allows multiple entries for the same key.

---

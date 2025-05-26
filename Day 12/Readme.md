# 🧠 Notes on `map`, `unordered_map`, `set`, `unordered_set`, and `multimap` in C++

---

## 📌 1. Comparison Overview

| Data Structure        | Key Unique | Ordered?    | Duplicates? | Avg Time (Insert/Search) | Underlying Structure |
| --------------------- | ---------- | ----------- | ----------- | ------------------------ | -------------------- |
| `unordered_map`       | ✅ Yes      | ❌ No        | ❌ No        | O(1)                     | Hash Table           |
| `map` (`ordered_map`) | ✅ Yes      | ✅ Yes (ASC) | ❌ No        | O(log n)                 | Red-Black Tree (BST) |
| `unordered_set`       | ✅ Yes      | ❌ No        | ❌ No        | O(1)                     | Hash Table           |
| `set`                 | ✅ Yes      | ✅ Yes (ASC) | ❌ No        | O(log n)                 | Red-Black Tree (BST) |
| `multimap`            | ❌ No       | ✅ Yes (ASC) | ✅ Yes       | O(log n)                 | Red-Black Tree (BST) |

> ⚠️ Average time for `unordered_*` structures depends on hash function; worst case can degrade to O(n).

---

## ⏱️ 2. Time Complexity Summary

| Operation | `map`    | `unordered_map` | `set`    | `unordered_set` | `multimap` |
| --------- | -------- | --------------- | -------- | --------------- | ---------- |
| Insert    | O(log n) | O(1) avg        | O(log n) | O(1) avg        | O(log n)   |
| Search    | O(log n) | O(1) avg        | O(log n) | O(1) avg        | O(log n)   |
| Erase     | O(log n) | O(1) avg        | O(log n) | O(1) avg        | O(log n)   |

---

## 🧪 3. Syntax & Examples

### ✅ `unordered_map`

```cpp
unordered_map<int, string> um;
um[1] = "A";
um[2] = "B";
if (um.count(2)) cout << um[2];
```

### ✅ `map` (ordered)

```cpp
map<int, string> om;
om[1] = "A";
om[3] = "C";
om[2] = "B";

for (auto& p : om)
    cout << p.first << " => " << p.second;  // Sorted by key
```

### ✅ `unordered_set`

```cpp
unordered_set<int> us;
us.insert(5);
us.insert(10);
if (us.find(5) != us.end()) cout << "Found";
```

### ✅ `set`

```cpp
set<int> s = {3, 1, 4, 2};
for (int x : s) cout << x << " ";  // Output: 1 2 3 4
```

### ✅ `multimap`

```cpp
multimap<string, int> mm;
mm.insert({"a", 1});
mm.insert({"a", 2});
mm.insert({"b", 3});

auto range = mm.equal_range("a");
for (auto it = range.first; it != range.second; ++it)
    cout << it->second << " ";  // Output: 1 2
```

---

## 🚫 4. Pitfalls & Notes

* ❗ `unordered_map` & `unordered_set` **do not maintain order**.
* ⚠️ `multimap` allows **duplicate keys**, unlike `map`.
* 🔁 `set` and `map` maintain **sorted order**, useful when traversing in order.
* 🛑 You cannot modify keys directly in `map`, `set`, or `multimap` after insertion.
* ⛓️ For `multimap`, use `.equal_range(key)` to access all values of a repeated key.

---

## 💡 5. When to Use What?

| Use Case                                | Recommended                       |
| --------------------------------------- | --------------------------------- |
| Fast lookup without ordering            | `unordered_map` / `unordered_set` |
| Need ordered traversal                  | `map` / `set`                     |
| Count of elements, word frequency, etc. | `unordered_map`                   |
| Storing unique elements                 | `set` / `unordered_set`           |
| Duplicate keys with sorted retrieval    | `multimap`                        |
| Custom sorting on keys                  | `map` / `set`                     |

---

## 📘 6. Practice Problems

### 🔸 Hash Maps

* [Two Sum](https://leetcode.com/problems/two-sum/)
* [Longest Consecutive Sequence](https://leetcode.com/problems/longest-consecutive-sequence/)
* [Group Anagrams](https://leetcode.com/problems/group-anagrams/)

### 🔸 Sets

* [Intersection of Two Arrays](https://leetcode.com/problems/intersection-of-two-arrays/)
* [Contains Duplicate](https://leetcode.com/problems/contains-duplicate/)
* [Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/)

### 🔸 Multimap-Like Scenarios

* [Reorder Data in Log Files](https://leetcode.com/problems/reorder-data-in-log-files/)
* [Sort Characters By Frequency](https://leetcode.com/problems/sort-characters-by-frequency/)
* [Design Leaderboard](https://leetcode.com/problems/design-a-leaderboard/)
* [Top K Frequent Words](https://leetcode.com/problems/top-k-frequent-words/)

---

## 🧰 7. Glossary

* 🔹 **Hash Table**: Stores key-value pairs with average O(1) lookup.
* 🔹 **Red-Black Tree**: Self-balancing BST (O(log n) operations).
* 🔹 **Multimap**: Allows duplicate keys; maintains sorted order.

---

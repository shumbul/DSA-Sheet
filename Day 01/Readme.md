# 📝 Notes on `map` and `unordered_map` in C++

---

## 📌 1. Time Complexity

| Data Structure     | Operation | Average Case | Worst Case | Remarks                                      |
|--------------------|-----------|--------------|------------|----------------------------------------------|
| `map`              | Insert    | O(log n)     | O(log n)   | Implemented using Red-Black Tree             |
|                    | Search    | O(log n)     | O(log n)   |                                              |
|                    | Erase     | O(log n)     | O(log n)   |                                              |
|                    | Count     | O(log n)     | O(log n)   |                                              |
| `unordered_map`    | Insert    | O(1)         | O(n)       | Hash table, collisions can degrade to O(n)   |
|                    | Search    | O(1)         | O(n)       |                                              |
|                    | Erase     | O(1)         | O(n)       |                                              |
|                    | Count     | O(1)         | O(n)       |                                              |

> ✅ **Note:** In most coding interviews and contests, we consider **average-case complexities** since worst-case for `unordered_map` is rare with good hash functions.

---

## 🔍 2. Checking if an Element Exists in a Map

Use either of the following:

```
if (mp.count(target - nums[i]) > 0) {
    // Element exists
}

// OR

if (mp.find(target - nums[i]) != mp.end()) {
    // Element exists
}

```

## 🔁 3. Traversing a Map

There are multiple ways to traverse a map depending on its value type.

### ✅ Example 1: Traversing `map<int, int>`

```
map<int, int> m;
for (int i = 0; i < n; i++)
    m[arr[i]]++;

// Printing the map
cout << "Element\t\tFrequency" << endl;
for (auto i : m)
    cout << i.first << "\t\t" << i.second << endl;

```

### ✅ Example 2: Traversing `map<string, vector<string>>`

```
map<string, vector<string>> words;
vector<vector<string>> ans;

for (auto& value : words) {
    auto val = value.second;

    // Since it's a map of vectors, explicitly access the values
    ans.push_back(val);
}

return ans;

```

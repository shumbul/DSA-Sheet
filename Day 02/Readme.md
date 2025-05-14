# 🧵 Notes on Common String STL Functions in C++

---

## ✨ Declaration

```
string s = "hello";
````

---

## 🔧 Common Operations

| Operation        | Code Example                          | Description                         |
| ---------------- | ------------------------------------- | ----------------------------------- |
| Length / Size    | `s.length()` / `s.size()`             | Returns number of characters        |
| Append           | `s += "world"` or `s.append("world")` | Adds to the end of the string       |
| Insert           | `s.insert(2, "xx")`                   | Inserts at a given index            |
| Erase            | `s.erase(2, 3)`                       | Erases 3 chars from index 2         |
| Substring        | `s.substr(1, 3)`                      | Substring from index 1 of length 3  |
| Find             | `s.find("lo")`                        | Returns starting index of substring |
| Reverse          | `reverse(s.begin(), s.end())`         | Reverses the entire string          |
| Sort             | `sort(s.begin(), s.end())`            | Sorts characters in the string      |
| Compare          | `s1.compare(s2)`                      | Returns 0 if equal                  |
| Push / Pop back  | `s.push_back('x')`, `s.pop_back()`    | Adds or removes last character      |
| Clear            | `s.clear()`                           | Empties the string                  |
| Check empty      | `s.empty()`                           | Returns true if string is empty     |
| Access character | `s[i]` or `s.at(i)`                   | Get char at index i                 |

---

## 🔁 Traversing a String

```
string s = "hello";

// Range-based loop
for (char c : s) {
    cout << c << " ";
}

// Index-based loop
for (int i = 0; i < s.size(); i++) {
    cout << s[i] << " ";
}
```

---

## 🧠 Tips

* `s.find()` returns `string::npos` if not found.
* `s.substr(start)` gives substring from start to end.
* Always prefer `s.empty()` over `s.size() == 0` for readability.
* `s.compare(s2) == 0` means strings are equal.

---

These STL functions are frequently used in interview questions like:

* **Valid Anagram**
* **Longest Substring Without Repeating Characters**
* **String Reversal**
* **Group Anagrams**


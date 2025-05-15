# 📚 Notes on C++ Data Types, Type Casting & Control Flow

---

## 🧮 1. Data Types in C++

| Data Type      | Example Declaration      | Description                       |
|----------------|--------------------------|-----------------------------------|
| `int`          | `int a = 10;`            | Integer (4 bytes)                 |
| `float`        | `float b = 3.14;`        | Floating point (4 bytes)         |
| `double`       | `double pi = 3.1415;`    | Double precision (8 bytes)       |
| `char`         | `char ch = 'A';`         | Character (1 byte)               |
| `bool`         | `bool isTrue = true;`    | Boolean                          |
| `string`       | `string s = "hello";`    | Sequence of characters (STL)     |
| `long`         | `long l = 100000;`       | Larger integer (≥4 bytes)        |
| `long long`    | `long long ll = 1e18;`   | Very large integer (≥8 bytes)    |

---

## 🔀 2. Type Casting in C++

Useful for controlling precision or resolving type mismatches in expressions.

```
char c = 'A';
cout << (int)(c);        // Outputs: 65 (ASCII value)

char lower = (char)(tolower('B'));   // Converts and stores as char
int ascii = (int)(tolower('B'));     // Stores ASCII as int

double d = 3.5;
int x = (int)d;          // x = 3 (truncates decimal part)
````

* Use **`(type)`** before a value to cast it explicitly.
* Especially helpful in:

  * Using functions like `tolower()`, `toupper()`
  * Performing operations between `int` and `double`
  * Ensuring correct output type in expressions

---

## 🔁 3. Control Flow

### ✅ `if`, `else if`, `else`

```
int x = 10;

if (x > 0) {
    cout << "Positive";
} else if (x < 0) {
    cout << "Negative";
} else {
    cout << "Zero";
}
```

---

### ✅ `for` Loop

```
for (int i = 0; i < 5; i++) {
    cout << i << " ";
}
```

#### 🔹 Range-based loop (C++11+)

```
vector<int> v = {1, 2, 3};

for (int val : v) {
    cout << val << " ";
}
```

#### 🔹 Using iterators

```
for (auto it = v.begin(); it != v.end(); it++) {
    cout << *it << " ";
}
```

---

### ✅ `while` Loop

```
int i = 0;

while (i < 5) {
    cout << i << " ";
    i++;
}
```

---

### ✅ `do-while` Loop

```
int i = 0;

do {
    cout << i << " ";
    i++;
} while (i < 5);
```

---

### ⚠️ Common Tips

* Avoid infinite loops: ensure loop conditions update.
* Use `do-while` only when logic **must run at least once**.
* Prefer range-based loops for readability with containers like `vector` or `string`.

--- 

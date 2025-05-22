## 📌 Pointers, Address-of Operator, Lower Bound & Upper Bound (C++ STL)

---

### 🔹 Address-of Operator `&`

* The `&` operator is used to get the **memory address** of a variable.

```cpp
int x = 10;
cout << &x;  // prints memory address of x
```

🧠 Use-case: Useful in pointer assignments or memory-level operations.

---

### 🔹 Pointers

* A **pointer** is a variable that stores the address of another variable.

```cpp
int x = 10;
int* ptr = &x;     // pointer to int
cout << *ptr;      // dereferencing, prints 10
```

| Term       | Meaning                                   |
| ---------- | ----------------------------------------- |
| `int* ptr` | Declares a pointer to an integer          |
| `&x`       | Address of variable `x`                   |
| `*ptr`     | Value stored at the address held by `ptr` |

🧩 **Use-case**: Dynamic memory, passing by reference, arrays.

---

### 🔹 `lower_bound()` in C++

* Returns an **iterator** pointing to the first element **not less than** the given value.
* Works on sorted ranges (`[first, last)`).

```cpp
vector<int> v = {1, 3, 3, 5, 8};
auto it = lower_bound(v.begin(), v.end(), 3);
cout << *it;  // Output: 3
```

| Input Value | lower\_bound Result |
| ----------- | ------------------- |
| 2           | 3                   |
| 3           | 3                   |
| 4           | 5                   |

🧠 Think of it as: **“Where can this value go without violating the order?”**

---

### 🔹 `upper_bound()` in C++

* Returns an **iterator** to the first element **greater than** the given value.

```cpp
vector<int> v = {1, 3, 3, 5, 8};
auto it = upper_bound(v.begin(), v.end(), 3);
cout << *it;  // Output: 5
```

| Input Value | upper\_bound Result |
| ----------- | ------------------- |
| 2           | 3                   |
| 3           | 5                   |
| 5           | 8                   |

🧠 Use-case: Counting frequencies in sorted arrays, binary search tweaks.

---

### ✅ Summary Table

| Concept       | Purpose                          | Example Output                      |
| ------------- | -------------------------------- | ----------------------------------- |
| `&x`          | Address of variable `x`          | 0x7ffe...                           |
| `*ptr`        | Dereference pointer to get value | 10                                  |
| `lower_bound` | First element ≥ value            | lower\_bound(v.begin(), ..., 3) → 3 |
| `upper_bound` | First element > value            | upper\_bound(v.begin(), ..., 3) → 5 |

---  
  
### 📚 Quiz Time
  
**Q1. What does the `&` operator do in C++?**  
a) It performs bitwise AND operation  
b) It multiplies two numbers  
c) It returns the address of a variable  
d) It compares two variables  
  
<details>  
<summary>Show Answer</summary>  
✅ **Answer:** c) It returns the address of a variable    
</details>  
  
---  
  
**Q2. Which of the following is NOT a type of pointer in C++?**  
a) Null Pointer  
b) Wild Pointer  
c) Smart Pointer  
d) Static Pointer  
  
<details>  
<summary>Show Answer</summary>  
✅ **Answer:** d) Static Pointer    
</details>  
  
---  
  
**Q3. What does the `*` operator do when used with a pointer?**  
a) Allocates memory  
b) Declares a pointer  
c) Dereferences a pointer  
d) Adds an address  
  
<details>  
<summary>Show Answer</summary>  
✅ **Answer:** c) Dereferences a pointer    
</details>  
  
---  
  
**Q4. Which function returns the first element not less than the target?**  
a) binary\_search()  
b) upper\_bound()  
c) lower\_bound()  
d) find()  
  
<details>  
<summary>Show Answer</summary>  
✅ **Answer:** c) lower_bound()    
</details>  
  
---  
  
**Q5. What does `upper_bound()` return in a sorted array?**  
a) First element equal to the target  
b) Last element  
c) First element greater than target  
d) First element less than target  
  
<details>  
<summary>Show Answer</summary>  
✅ **Answer:** c) First element greater than target    
</details>  
  
---  
  
**Q6. What is the output of this code?**  
  
```cpp  
int arr[] = {10, 20, 30};  
cout << *(arr + 1);  
```  
  
a) 10  
b) 20  
c) 30  
d) Error  
  
<details>  
<summary>Show Answer</summary>  
✅ **Answer:** b) 20    
</details>  
  
---  
  
**Q7. Which header is needed for `lower_bound()` and `upper_bound()`?**  
a) \<iostream>  
b) \<math.h>  
c) \<vector>  
d) \<algorithm>  
  
<details>  
<summary>Show Answer</summary>  
✅ **Answer:** d) \<algorithm\>    
</details>  
  
---  
  
**Q8. Which of these pointers points to nowhere?**  
a) Null pointer  
b) Dangling pointer  
c) Wild pointer  
d) Constant pointer  
  
<details>  
<summary>Show Answer</summary>  
✅ **Answer:** a) Null pointer    
</details>  
  
---  
  
**Q9. What will this code print?**  
  
```cpp  
int x = 5;  
int* p = &x;  
*p = 10;  
cout << x;  
```  
  
a) 5  
b) 10  
c) Address of x  
d) Garbage value  
  
<details>  
<summary>Show Answer</summary>  
✅ **Answer:** b) 10    
</details>  
  
---  
  
**Q10. Which one of these is true about `&x`?**  
a) It gets the value of x  
b) It adds 1 to x  
c) It gives the address of x  
d) It multiplies x by 2  
  
<details>  
<summary>Show Answer</summary>  
✅ **Answer:** c) It gives the address of x    
</details>  

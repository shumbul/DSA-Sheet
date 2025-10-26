# 🔗 Day 35: Linked List Fundamentals & Advanced Techniques

## 📚 Table of Contents
1. [Linked List Basics](#linked-list-basics)
2. [Core Patterns & Techniques](#core-patterns--techniques)
3. [Common Problem Types](#common-problem-types)
4. [Implementation Templates](#implementation-templates)
5. [Time & Space Complexity](#time--space-complexity)
6. [Interview Tips](#interview-tips)

---

## 🏗️ Linked List Basics

### Node Structure
```cpp
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
```

### Key Properties
- **Dynamic Size**: Can grow/shrink during runtime
- **Memory Efficient**: Only allocates memory as needed
- **Sequential Access**: Must traverse from head to reach any element
- **No Random Access**: Cannot directly access elements by index

---

## 🎯 Core Patterns & Techniques

### 1. **Two Pointer Technique** 🎭
The most powerful pattern for linked list problems.

#### **Fast & Slow Pointers (Floyd's Algorithm)**
```cpp
// Template for cycle detection
bool hasCycle(ListNode* head) {
    if (!head || !head->next) return false;
    
    ListNode* slow = head;
    ListNode* fast = head;
    
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        
        if (slow == fast) return true;
    }
    return false;
}
```

**Applications:**
- Cycle detection
- Finding middle element
- Checking if palindrome
- Finding nth node from end

#### **Leading & Trailing Pointers**
```cpp
// Template for nth node from end
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    
    ListNode* first = dummy;
    ListNode* second = dummy;
    
    // Move first pointer n+1 steps ahead
    for (int i = 0; i <= n; i++) {
        first = first->next;
    }
    
    // Move both pointers until first reaches end
    while (first) {
        first = first->next;
        second = second->next;
    }
    
    second->next = second->next->next;
    return dummy->next;
}
```

### 2. **Dummy Node Pattern** 🎪
Simplifies edge cases and makes code cleaner.

```cpp
// Template with dummy node
ListNode* processLinkedList(ListNode* head) {
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* current = dummy;
    
    while (current->next) {
        // Process nodes
        current = current->next;
    }
    
    return dummy->next;  // Return actual head
}
```

**When to use:**
- When head might be removed/modified
- When merging lists
- When inserting at beginning

### 3. **Reversal Patterns** 🔄

#### **Iterative Reversal**
```cpp
ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* current = head;
    
    while (current) {
        ListNode* nextTemp = current->next;
        current->next = prev;
        prev = current;
        current = nextTemp;
    }
    
    return prev;
}
```

#### **Recursive Reversal**
```cpp
ListNode* reverseList(ListNode* head) {
    if (!head || !head->next) return head;
    
    ListNode* newHead = reverseList(head->next);
    head->next->next = head;
    head->next = nullptr;
    
    return newHead;
}
```

---

## 🧩 Common Problem Types

### 1. **Cycle Problems** 🔄
- **Detection**: Floyd's cycle detection
- **Finding Start**: After detecting cycle, reset one pointer to head
- **Cycle Length**: Count steps between meeting points

### 2. **Palindrome Check** 🪞
**Strategy**: Find middle → Reverse second half → Compare
```cpp
bool isPalindrome(ListNode* head) {
    // Find middle using fast/slow pointers
    ListNode* slow = head;
    ListNode* fast = head;
    
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    // Reverse second half
    ListNode* secondHalf = reverseList(slow);
    
    // Compare both halves
    ListNode* firstHalf = head;
    while (secondHalf) {
        if (firstHalf->val != secondHalf->val) return false;
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }
    
    return true;
}
```

### 3. **Merging Lists** 🤝
```cpp
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode* dummy = new ListNode(0);
    ListNode* current = dummy;
    
    while (l1 && l2) {
        if (l1->val <= l2->val) {
            current->next = l1;
            l1 = l1->next;
        } else {
            current->next = l2;
            l2 = l2->next;
        }
        current = current->next;
    }
    
    // Attach remaining nodes
    current->next = l1 ? l1 : l2;
    
    return dummy->next;
}
```

### 4. **Node Removal** ❌
- **Remove by value**: Traverse and skip matching nodes
- **Remove duplicates**: Use hash set or sort + remove
- **Remove nth from end**: Two-pointer technique

---

## 💻 Implementation Templates

### Template 1: Basic Traversal
```cpp
void traverseList(ListNode* head) {
    ListNode* current = head;
    while (current) {
        // Process current node
        cout << current->val << " ";
        current = current->next;
    }
}
```

### Template 2: Two-Pointer Operations
```cpp
ListNode* twoPointerOperation(ListNode* head) {
    if (!head) return nullptr;
    
    ListNode* slow = head;
    ListNode* fast = head;
    
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        
        // Check condition or perform operation
        if (/* condition */) {
            // Handle the case
        }
    }
    
    return slow;  // Usually returns middle or result
}
```

### Template 3: List Modification
```cpp
ListNode* modifyList(ListNode* head) {
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* current = dummy;
    
    while (current->next) {
        if (/* condition to modify */) {
            ListNode* nodeToRemove = current->next;
            current->next = current->next->next;
            delete nodeToRemove;
        } else {
            current = current->next;
        }
    }
    
    return dummy->next;
}
```

---

## ⏱️ Time & Space Complexity

| Operation | Time | Space | Notes |
|-----------|------|-------|-------|
| **Traversal** | O(n) | O(1) | Visit each node once |
| **Search** | O(n) | O(1) | Worst case: element at end |
| **Insertion** | O(1) | O(1) | If position known |
| **Deletion** | O(1) | O(1) | If node reference available |
| **Reversal** | O(n) | O(1) | Iterative approach |
| **Cycle Detection** | O(n) | O(1) | Floyd's algorithm |
| **Find Middle** | O(n) | O(1) | Two-pointer technique |
| **Merge Two Lists** | O(n+m) | O(1) | Where n,m are list lengths |

---

## 🎯 Interview Tips

### **Before You Code:**
1. **Clarify Requirements**: Ask about duplicates, cycles, constraints
2. **Draw Examples**: Visualize the problem with small examples
3. **Identify Pattern**: Two pointers? Reversal? Dummy node?
4. **Handle Edge Cases**: Empty list, single node, cycles

### **Common Edge Cases:**
- `head == nullptr` (empty list)
- Single node list
- Lists with cycles
- Lists of different lengths
- All nodes have same value

### **Coding Best Practices:**
```cpp
// Always check for null pointers
if (!head || !head->next) return head;

// Use dummy nodes for cleaner code
ListNode* dummy = new ListNode(0);
dummy->next = head;

// Be careful with pointer assignments
ListNode* next = current->next;  // Store before modifying
current->next = prev;
prev = current;
current = next;
```

### **Common Mistakes to Avoid:**
1. **Memory Leaks**: Don't forget to delete removed nodes
2. **Lost References**: Store next pointer before modifying links
3. **Infinite Loops**: Ensure loop termination conditions
4. **Off-by-One Errors**: Be careful with counting and indexing

### **Optimization Hints:**
- Use two pointers instead of counting length
- Dummy nodes simplify edge case handling
- In-place operations save space
- Consider recursive solutions for tree-like problems

---

## 🏆 Problem-Solving Framework

### Step 1: **Understand the Problem**
- What type of operation? (Search, modify, detect pattern)
- Any constraints? (Sorted? Cycles allowed?)
- Expected time/space complexity?

### Step 2: **Choose the Right Pattern**
- **Two Pointers**: Cycle detection, middle finding, nth from end
- **Dummy Node**: Head modifications, merging, insertions
- **Reversal**: Palindrome checks, group reversals
- **Stack/Recursion**: Complex manipulations, backtracking

### Step 3: **Implement with Care**
- Handle edge cases first
- Use clear variable names
- Test with small examples
- Verify pointer assignments

---

## 🎮 Practice Strategy

### **Beginner Level:**
1. Basic traversal and printing
2. Find length of linked list
3. Search for an element

### **Intermediate Level:**
4. Remove duplicates from sorted list
5. Merge two sorted lists
6. Find middle element

### **Advanced Level:**
7. Detect and remove cycles
8. Reverse nodes in k-groups
9. Copy list with random pointers

---

*Remember: Linked lists are all about pointer manipulation. Master the patterns, handle edge cases carefully, and always visualize your operations!* 🚀
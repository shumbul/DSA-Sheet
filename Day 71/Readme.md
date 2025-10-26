# 🌳 Day 71: Trie (Prefix Tree) - Complete Implementation Guide

## 📚 Table of Contents
1. [What is a Trie?](#what-is-a-trie)
2. [Core Implementation](#core-implementation)
3. [Advanced Operations](#advanced-operations)
4. [Problem Patterns](#problem-patterns)
5. [Optimization Techniques](#optimization-techniques)
6. [Interview Strategies](#interview-strategies)

---

## 🤔 What is a Trie?

A **Trie** (pronounced "try") is a tree-like data structure used to store a dynamic set of strings, where each node represents a single character. It's also called a **Prefix Tree** because it efficiently handles prefix-based operations.

### **Visual Example:**
```
Words: ["cat", "car", "card", "care", "careful", "cats"]

         root
          |
          c
          |
          a
         / \
        t   r
        |   |\
        *   d e
        |   * |\
        s     * f
        |       |\
        *       u l
                | |
                l *
                |
                *
```
`*` = End of word marker

### **Key Properties:**
- **Efficient Prefix Operations**: Search, insert, delete in O(m) time where m = word length
- **Space Sharing**: Common prefixes are stored only once
- **Lexicographic Ordering**: In-order traversal gives sorted strings
- **Memory Intensive**: Each node can have up to 26 children (for lowercase English)

---

## 💻 Core Implementation

### **Basic Trie Node Structure**
```cpp
class TrieNode {
public:
    vector<TrieNode*> children;
    bool isEndOfWord;
    
    TrieNode() {
        children.resize(26, nullptr);  // For 'a' to 'z'
        isEndOfWord = false;
    }
    
    ~TrieNode() {
        for (TrieNode* child : children) {
            delete child;
        }
    }
};
```

### **Complete Trie Implementation**
```cpp
class Trie {
private:
    TrieNode* root;
    
public:
    Trie() {
        root = new TrieNode();
    }
    
    ~Trie() {
        delete root;
    }
    
    // Insert a word into the trie
    void insert(string word) {
        TrieNode* current = root;
        
        for (char c : word) {
            int index = c - 'a';
            if (!current->children[index]) {
                current->children[index] = new TrieNode();
            }
            current = current->children[index];
        }
        
        current->isEndOfWord = true;
    }
    
    // Search for a complete word
    bool search(string word) {
        TrieNode* current = root;
        
        for (char c : word) {
            int index = c - 'a';
            if (!current->children[index]) {
                return false;
            }
            current = current->children[index];
        }
        
        return current->isEndOfWord;
    }
    
    // Check if any word starts with given prefix
    bool startsWith(string prefix) {
        TrieNode* current = root;
        
        for (char c : prefix) {
            int index = c - 'a';
            if (!current->children[index]) {
                return false;
            }
            current = current->children[index];
        }
        
        return true;
    }
    
    // Delete a word from trie
    bool deleteWord(string word) {
        return deleteHelper(root, word, 0);
    }
    
private:
    bool deleteHelper(TrieNode* node, string& word, int index) {
        if (index == word.length()) {
            // Reached end of word
            if (!node->isEndOfWord) return false;  // Word doesn't exist
            
            node->isEndOfWord = false;
            
            // If node has no children, it can be deleted
            return !hasChildren(node);
        }
        
        int charIndex = word[index] - 'a';
        TrieNode* childNode = node->children[charIndex];
        
        if (!childNode) return false;  // Word doesn't exist
        
        bool shouldDeleteChild = deleteHelper(childNode, word, index + 1);
        
        if (shouldDeleteChild) {
            delete childNode;
            node->children[charIndex] = nullptr;
            
            // Return true if current node has no children and is not end of another word
            return !node->isEndOfWord && !hasChildren(node);
        }
        
        return false;
    }
    
    bool hasChildren(TrieNode* node) {
        for (TrieNode* child : node->children) {
            if (child) return true;
        }
        return false;
    }
};
```

---

## 🚀 Advanced Operations

### **1. Auto-Complete / Word Suggestions**
```cpp
vector<string> getWordsWithPrefix(string prefix) {
    vector<string> result;
    TrieNode* prefixNode = findPrefixNode(prefix);
    
    if (prefixNode) {
        string currentWord = prefix;
        dfsCollectWords(prefixNode, currentWord, result);
    }
    
    return result;
}

private:
TrieNode* findPrefixNode(string prefix) {
    TrieNode* current = root;
    
    for (char c : prefix) {
        int index = c - 'a';
        if (!current->children[index]) {
            return nullptr;
        }
        current = current->children[index];
    }
    
    return current;
}

void dfsCollectWords(TrieNode* node, string& currentWord, vector<string>& result) {
    if (node->isEndOfWord) {
        result.push_back(currentWord);
    }
    
    for (int i = 0; i < 26; i++) {
        if (node->children[i]) {
            currentWord.push_back('a' + i);
            dfsCollectWords(node->children[i], currentWord, result);
            currentWord.pop_back();  // Backtrack
        }
    }
}
```

### **2. Longest Common Prefix**
```cpp
string longestCommonPrefix(vector<string>& words) {
    if (words.empty()) return "";
    
    // Build trie with all words
    for (string word : words) {
        insert(word);
    }
    
    string lcp = "";
    TrieNode* current = root;
    
    while (current) {
        int childCount = 0;
        int nextIndex = -1;
        
        // Count non-null children
        for (int i = 0; i < 26; i++) {
            if (current->children[i]) {
                childCount++;
                nextIndex = i;
            }
        }
        
        // If more than one child or end of word, stop
        if (childCount != 1 || current->isEndOfWord) {
            break;
        }
        
        lcp += ('a' + nextIndex);
        current = current->children[nextIndex];
    }
    
    return lcp;
}
```

### **3. Word Search in Grid (Using Trie)**
```cpp
class TrieWordSearch {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        // Build trie with all words
        TrieNode* root = new TrieNode();
        for (string word : words) {
            insertWord(root, word);
        }
        
        vector<string> result;
        int rows = board.size(), cols = board[0].size();
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                dfs(board, i, j, root, "", result);
            }
        }
        
        return result;
    }
    
private:
    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* node, 
             string currentWord, vector<string>& result) {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || 
            board[i][j] == '#') {
            return;
        }
        
        char c = board[i][j];
        int index = c - 'a';
        
        if (!node->children[index]) return;
        
        node = node->children[index];
        currentWord += c;
        
        if (node->isEndOfWord) {
            result.push_back(currentWord);
            node->isEndOfWord = false;  // Avoid duplicates
        }
        
        board[i][j] = '#';  // Mark as visited
        
        // Explore all 4 directions
        dfs(board, i+1, j, node, currentWord, result);
        dfs(board, i-1, j, node, currentWord, result);
        dfs(board, i, j+1, node, currentWord, result);
        dfs(board, i, j-1, node, currentWord, result);
        
        board[i][j] = c;  // Backtrack
    }
};
```

---

## 🎯 Problem Patterns

### **Pattern 1: Dictionary Operations**
- **Problems**: Implement Trie, Word Search
- **Key Insight**: Direct mapping of characters to children
- **Template**: Basic insert/search/delete operations

### **Pattern 2: Prefix Matching**
- **Problems**: Longest Word in Dictionary, Auto-complete
- **Key Insight**: Traverse trie following prefix, then collect all words
- **Template**: DFS from prefix endpoint

### **Pattern 3: Multiple String Processing**
- **Problems**: Word Search II, Stream of Characters
- **Key Insight**: Build trie first, then process queries efficiently
- **Template**: Build trie + optimized search

### **Pattern 4: Lexicographic Operations**
- **Problems**: Lexicographically smallest string, K-th string
- **Key Insight**: In-order traversal gives lexicographic order
- **Template**: DFS with ordering constraints

---

## ⚡ Optimization Techniques

### **1. Memory Optimization**
```cpp
// Use unordered_map instead of fixed array for sparse data
class OptimizedTrieNode {
public:
    unordered_map<char, OptimizedTrieNode*> children;
    bool isEndOfWord;
    
    OptimizedTrieNode() : isEndOfWord(false) {}
};
```

**When to use:**
- Large alphabet (not just a-z)
- Sparse trie (few words relative to possible combinations)
- Memory-constrained environments

### **2. Compressed Trie (Radix Tree)**
```cpp
class CompressedTrieNode {
public:
    string edgeLabel;  // Store substring instead of single char
    unordered_map<char, CompressedTrieNode*> children;
    bool isEndOfWord;
};
```

**Benefits:**
- Reduces space for long unique suffixes
- Faster traversal for unique paths
- More complex implementation

### **3. Lazy Deletion**
```cpp
class LazyTrieNode {
public:
    vector<TrieNode*> children;
    bool isEndOfWord;
    bool isDeleted;  // Mark as deleted instead of actual deletion
    
    LazyTrieNode() : isEndOfWord(false), isDeleted(false) {
        children.resize(26, nullptr);
    }
};
```

---

## 🎯 Interview Strategies

### **Problem Identification:**
Look for these keywords:
- "Prefix" operations
- "Auto-complete" or "suggestions"
- "Dictionary" of words
- "Stream of characters"
- Multiple string queries

### **When to Use Trie:**
✅ **Good for:**
- Multiple prefix queries
- Auto-complete systems
- Word validation with large dictionary
- Finding words with common prefixes

❌ **Not ideal for:**
- Single word operations (use hash table instead)
- Numeric data (unless treating as strings)
- Very large alphabets with sparse data

### **Common Interview Questions:**
1. **"Implement a basic trie"** → Use standard template
2. **"Find all words starting with prefix"** → DFS from prefix node
3. **"Word search in 2D grid"** → Backtracking + trie
4. **"Longest word in dictionary"** → Level-order traversal
5. **"Replace words with roots"** → Trie + string processing

### **Time & Space Analysis:**
| Operation | Time | Space | Notes |
|-----------|------|-------|-------|
| **Insert** | O(m) | O(m) | m = word length |
| **Search** | O(m) | O(1) | - |
| **Delete** | O(m) | O(1) | Recursive approach |
| **Prefix Search** | O(p + n) | O(n) | p = prefix len, n = results |
| **Auto-complete** | O(p + ALPHABET^k) | O(n) | k = max depth |

### **Implementation Tips:**
```cpp
// 1. Always check for null pointers
if (!node->children[index]) {
    return false;  // or create new node for insert
}

// 2. Use index calculation for characters
int index = c - 'a';  // For lowercase a-z
int index = c - 'A';  // For uppercase A-Z
int index = c - '0';  // For digits 0-9

// 3. Handle end-of-word marker carefully
node->isEndOfWord = true;  // For insert
return node->isEndOfWord;   // For search

// 4. Memory management
~TrieNode() {
    for (TrieNode* child : children) {
        delete child;  // Recursive deletion
    }
}
```

### **Common Pitfalls:**
1. **Memory Leaks**: Always implement proper destructor
2. **Character Mapping**: Be careful with character-to-index conversion
3. **End Marker**: Don't forget to mark end of words
4. **Null Checks**: Always verify node existence before access
5. **Case Sensitivity**: Decide on case handling strategy upfront

---

## 🏆 Advanced Applications

### **1. IP Routing Tables**
- Store network prefixes efficiently
- Longest prefix matching for routing decisions

### **2. DNS Lookups**
- Reverse domain name storage
- Fast subdomain resolution

### **3. Compiler Design**
- Symbol table for identifiers
- Keyword recognition

### **4. Bioinformatics**
- DNA sequence matching
- Protein pattern recognition

---

## 🎮 Practice Progression

### **Beginner:**
1. Implement basic Trie (insert, search, startsWith)
2. Count words with given prefix
3. Find shortest unique prefix

### **Intermediate:**
4. Word Search II (2D grid + trie)
5. Replace Words (root replacement)
6. Longest Word in Dictionary

### **Advanced:**
7. Stream of Characters
8. Design Search Autocomplete System
9. Word Squares

---

*Master the Trie and you'll have a powerful tool for string processing and prefix operations! 🌟*
# 🔢 Day 61: Bit Manipulation Mastery

## 📚 Table of Contents
1. [Bit Manipulation Fundamentals](#bit-manipulation-fundamentals)
2. [Essential Operations](#essential-operations)
3. [Common Patterns](#common-patterns)
4. [Advanced Techniques](#advanced-techniques)
5. [Problem Categories](#problem-categories)
6. [Interview Strategy](#interview-strategy)

---

## 🧠 Bit Manipulation Fundamentals

Bit manipulation is one of the most powerful and efficient techniques in competitive programming and interviews. It operates directly on binary representations of numbers.

### **Why Bit Manipulation?**
- ⚡ **Ultra-fast**: Direct CPU operations
- 💾 **Memory efficient**: Compact data representation
- 🎯 **Elegant solutions**: Often leads to concise code
- 🔍 **Pattern recognition**: Many problems have hidden bit patterns

### **Binary Number System Refresher:**
```
Decimal:  5  =  101₂  = 1×2² + 0×2¹ + 1×2⁰
Bits:     4th 3rd 2nd 1st (from right, 0-indexed)
Powers:   2³  2²  2¹  2⁰
```

---

## ⚙️ Essential Operations

### **1. Basic Bitwise Operators**
```cpp
// AND (&) - Both bits must be 1
5 & 3   // 101 & 011 = 001 = 1

// OR (|) - At least one bit must be 1  
5 | 3   // 101 | 011 = 111 = 7

// XOR (^) - Bits must be different
5 ^ 3   // 101 ^ 011 = 110 = 6

// NOT (~) - Flip all bits
~5      // ~101 = ...11111010 (depends on integer size)

// Left Shift (<<) - Multiply by 2^n
5 << 2  // 101 << 2 = 10100 = 20

// Right Shift (>>) - Divide by 2^n
5 >> 1  // 101 >> 1 = 10 = 2
```

### **2. Fundamental Bit Tricks**
```cpp
class BitTricks {
public:
    // Check if number is even/odd
    bool isEven(int n) { return (n & 1) == 0; }
    bool isOdd(int n) { return (n & 1) == 1; }
    
    // Check if kth bit is set (0-indexed from right)
    bool isKthBitSet(int n, int k) {
        return (n & (1 << k)) != 0;
    }
    
    // Set kth bit
    int setKthBit(int n, int k) {
        return n | (1 << k);
    }
    
    // Clear kth bit
    int clearKthBit(int n, int k) {
        return n & ~(1 << k);
    }
    
    // Toggle kth bit
    int toggleKthBit(int n, int k) {
        return n ^ (1 << k);
    }
    
    // Check if number is power of 2
    bool isPowerOfTwo(int n) {
        return n > 0 && (n & (n - 1)) == 0;
    }
    
    // Count number of set bits (Hamming weight)
    int countSetBits(int n) {
        int count = 0;
        while (n) {
            count++;
            n &= (n - 1);  // Remove the rightmost set bit
        }
        return count;
    }
    
    // Find position of rightmost set bit (0-indexed)
    int rightmostSetBit(int n) {
        return n & (-n);  // Isolate rightmost set bit
    }
    
    // Multiply/Divide by powers of 2
    int multiplyBy2PowerK(int n, int k) { return n << k; }
    int divideBy2PowerK(int n, int k) { return n >> k; }
};
```

---

## 🎯 Common Patterns

### **Pattern 1: Single Number Problems**
```cpp
class SingleNumberPatterns {
public:
    // Find single number when all others appear twice
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for (int num : nums) {
            result ^= num;  // XOR cancels out duplicates
        }
        return result;
    }
    
    // Find single number when all others appear thrice
    int singleNumberII(vector<int>& nums) {
        int ones = 0, twos = 0;
        
        for (int num : nums) {
            twos |= (ones & num);  // Add to twos if already in ones
            ones ^= num;           // Add to ones or remove if already there
            
            // Remove numbers that appear thrice
            int common = ones & twos;
            ones &= ~common;
            twos &= ~common;
        }
        
        return ones;
    }
    
    // Find two single numbers when all others appear twice
    vector<int> singleNumberIII(vector<int>& nums) {
        int xorAll = 0;
        for (int num : nums) {
            xorAll ^= num;
        }
        
        // Find rightmost set bit in XOR result
        int rightmostBit = xorAll & (-xorAll);
        
        int group1 = 0, group2 = 0;
        for (int num : nums) {
            if (num & rightmostBit) {
                group1 ^= num;
            } else {
                group2 ^= num;
            }
        }
        
        return {group1, group2};
    }
};
```

### **Pattern 2: Subset Generation**
```cpp
class SubsetGeneration {
public:
    // Generate all subsets using bit manipulation
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> result;
        
        // Generate 2^n subsets
        for (int mask = 0; mask < (1 << n); mask++) {
            vector<int> subset;
            
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {  // Check if ith bit is set
                    subset.push_back(nums[i]);
                }
            }
            
            result.push_back(subset);
        }
        
        return result;
    }
    
    // Count subsets with given sum using bitmask DP
    int countSubsetsWithSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> dp;
        dp[0] = 1;  // Empty subset has sum 0
        
        for (int num : nums) {
            unordered_map<int, int> newDp = dp;
            for (auto [sum, count] : dp) {
                newDp[sum + num] += count;
            }
            dp = newDp;
        }
        
        return dp.count(target) ? dp[target] : 0;
    }
};
```

### **Pattern 3: Bit Counting & Analysis**
```cpp
class BitAnalysis {
public:
    // Count bits for numbers 0 to n
    vector<int> countBits(int n) {
        vector<int> dp(n + 1, 0);
        
        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i >> 1] + (i & 1);  // Use previous result + last bit
        }
        
        return dp;
    }
    
    // Find complement of number
    int findComplement(int num) {
        // Find the number of bits in num
        int bitLength = 0;
        int temp = num;
        while (temp) {
            bitLength++;
            temp >>= 1;
        }
        
        // Create mask with all 1s for the bit length
        unsigned int mask = (1U << bitLength) - 1;
        
        return num ^ mask;
    }
    
    // Hamming distance between two numbers
    int hammingDistance(int x, int y) {
        int xorResult = x ^ y;
        int distance = 0;
        
        while (xorResult) {
            distance++;
            xorResult &= (xorResult - 1);  // Remove rightmost set bit
        }
        
        return distance;
    }
    
    // Reverse bits of a 32-bit unsigned integer
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        
        for (int i = 0; i < 32; i++) {
            result = (result << 1) | (n & 1);
            n >>= 1;
        }
        
        return result;
    }
};
```

---

## 🚀 Advanced Techniques

### **1. Bit Masking for DP**
```cpp
class BitMaskDP {
public:
    // Traveling Salesman using bitmask DP
    int tsp(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> dp(1 << n, vector<int>(n, INT_MAX));
        
        dp[1][0] = 0;  // Start at city 0 with only city 0 visited
        
        for (int mask = 0; mask < (1 << n); mask++) {
            for (int u = 0; u < n; u++) {
                if (!(mask & (1 << u)) || dp[mask][u] == INT_MAX) continue;
                
                for (int v = 0; v < n; v++) {
                    if (mask & (1 << v)) continue;  // Already visited
                    
                    int newMask = mask | (1 << v);
                    dp[newMask][v] = min(dp[newMask][v], dp[mask][u] + graph[u][v]);
                }
            }
        }
        
        int result = INT_MAX;
        for (int i = 1; i < n; i++) {
            if (dp[(1 << n) - 1][i] != INT_MAX) {
                result = min(result, dp[(1 << n) - 1][i] + graph[i][0]);
            }
        }
        
        return result;
    }
    
    // Maximum AND subset
    int maxANDSubset(vector<int>& nums) {
        int maxAND = 0;
        
        // Find maximum possible AND
        for (int bit = 31; bit >= 0; bit--) {
            int candidate = maxAND | (1 << bit);
            int count = 0;
            
            for (int num : nums) {
                if ((num & candidate) == candidate) {
                    count++;
                }
            }
            
            if (count >= 2) {  // Need at least 2 numbers for subset
                maxAND = candidate;
            }
        }
        
        return maxAND;
    }
};
```

### **2. Bit Manipulation Optimizations**
```cpp
class BitOptimizations {
public:
    // Fast multiplication using bit shifts
    long long fastMultiply(long long a, long long b) {
        long long result = 0;
        
        while (b > 0) {
            if (b & 1) {
                result += a;
            }
            a <<= 1;
            b >>= 1;
        }
        
        return result;
    }
    
    // Fast exponentiation using bits
    long long fastPower(long long base, long long exp, long long mod) {
        long long result = 1;
        base %= mod;
        
        while (exp > 0) {
            if (exp & 1) {
                result = (result * base) % mod;
            }
            base = (base * base) % mod;
            exp >>= 1;
        }
        
        return result;
    }
    
    // Check if array has duplicate using bit set
    bool hasDuplicate(vector<int>& nums) {
        bitset<100001> seen;  // Assuming nums[i] <= 100000
        
        for (int num : nums) {
            if (seen[num]) return true;
            seen[num] = 1;
        }
        
        return false;
    }
    
    // Find missing number using XOR
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int xorAll = 0;
        
        // XOR all numbers from 0 to n
        for (int i = 0; i <= n; i++) {
            xorAll ^= i;
        }
        
        // XOR all numbers in array
        for (int num : nums) {
            xorAll ^= num;
        }
        
        return xorAll;  // Missing number remains
    }
};
```

---

## 📊 Problem Categories

### **Category 1: Number Properties**
- Check if power of 2/4
- Count set bits
- Find complement
- Reverse bits

### **Category 2: Array Problems**
- Single number variants
- Missing number
- Duplicate detection
- Majority element

### **Category 3: Subset Problems**
- Generate all subsets
- Subset sum with bitmask
- Maximum XOR subset
- Subset with given AND

### **Category 4: Optimization Problems**
- Fast arithmetic operations
- Space-efficient algorithms
- Bitmask DP problems

---

## 🎯 Interview Strategy

### **Problem Recognition:**
Look for these hints:
- "Single number" or "appears once/twice/thrice"
- "XOR" mentioned explicitly
- "Complement" or "flip bits"
- "Powers of 2"
- "Subset generation"
- "Missing number" in sequence

### **Key Insights to Remember:**
```cpp
// XOR Properties
a ^ a = 0          // Same numbers cancel out
a ^ 0 = a          // XOR with 0 gives original
a ^ b = b ^ a      // Commutative property

// Power of 2 Check
n > 0 && (n & (n-1)) == 0

// Remove rightmost set bit
n & (n-1)

// Isolate rightmost set bit
n & (-n)

// Check if kth bit is set
(n >> k) & 1  or  (n & (1 << k)) != 0

// Count set bits efficiently
while (n) {
    count++;
    n &= (n-1);  // Brian Kernighan's algorithm
}
```

### **Common Bit Manipulation Templates:**

#### **Template 1: Single Number Pattern**
```cpp
int singleNumber(vector<int>& nums) {
    int result = 0;
    for (int num : nums) {
        result ^= num;
    }
    return result;
}
```

#### **Template 2: Subset Generation**
```cpp
for (int mask = 0; mask < (1 << n); mask++) {
    for (int i = 0; i < n; i++) {
        if (mask & (1 << i)) {
            // Include element i in current subset
        }
    }
}
```

#### **Template 3: Bit Position Operations**
```cpp
// Set, clear, toggle, check bit
int setBit(int n, int k) { return n | (1 << k); }
int clearBit(int n, int k) { return n & ~(1 << k); }
int toggleBit(int n, int k) { return n ^ (1 << k); }
bool checkBit(int n, int k) { return (n & (1 << k)) != 0; }
```

### **Time Complexity Analysis:**
- **Basic operations**: O(1)
- **Counting bits**: O(log n) or O(number of set bits)
- **Subset generation**: O(2^n)
- **Bitmask DP**: O(2^n × n) typically

---

## 🏆 Advanced Applications

### **1. Gray Code Generation**
```cpp
vector<int> grayCode(int n) {
    vector<int> result;
    for (int i = 0; i < (1 << n); i++) {
        result.push_back(i ^ (i >> 1));  // Gray code formula
    }
    return result;
}
```

### **2. Maximum XOR of Two Numbers**
```cpp
int findMaximumXOR(vector<int>& nums) {
    int maxXOR = 0;
    int mask = 0;
    
    for (int i = 31; i >= 0; i--) {
        mask |= (1 << i);
        unordered_set<int> prefixes;
        
        for (int num : nums) {
            prefixes.insert(num & mask);
        }
        
        int candidate = maxXOR | (1 << i);
        
        for (int prefix : prefixes) {
            if (prefixes.count(candidate ^ prefix)) {
                maxXOR = candidate;
                break;
            }
        }
    }
    
    return maxXOR;
}
```

---

## 🎮 Practice Progression

### **Level 1: Fundamentals**
1. Number of 1 Bits
2. Power of Two
3. Number Complement

### **Level 2: Intermediate**
4. Single Number (all variants)
5. Missing Number
6. Hamming Distance

### **Level 3: Advanced**
7. Maximum XOR of Two Numbers
8. Subsets generation
9. Gray Code

---

*Master bit manipulation and you'll have a powerful tool for optimization and elegant problem-solving! 🔢*
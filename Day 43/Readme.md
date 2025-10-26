# 💰 Day 43: Advanced Dynamic Programming - Coin Change & Beyond

## 📚 Table of Contents
1. [Coin Change Pattern Family](#coin-change-pattern-family)
2. [Core DP Concepts](#core-dp-concepts)
3. [Problem Variations](#problem-variations)
4. [Advanced Patterns](#advanced-patterns)
5. [Optimization Techniques](#optimization-techniques)
6. [Interview Strategy](#interview-strategy)

---

## 💰 Coin Change Pattern Family

The **Coin Change** pattern is one of the most fundamental DP patterns, appearing in various forms across many problems. Understanding this pattern deeply opens doors to solving numerous optimization problems.

### **Pattern Recognition:**
- "Find minimum number of..."
- "Count ways to make..."
- "Can you make exactly..."
- "Unlimited supply" or "Use each item multiple times"

---

## 🧠 Core DP Concepts

### **1. Coin Change I - Minimum Coins**
**Problem**: Given coins and target amount, find minimum coins needed.

```cpp
class CoinChange {
public:
    // Bottom-up DP approach
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);  // Initialize with impossible value
        dp[0] = 0;  // Base case: 0 coins needed for amount 0
        
        for (int i = 1; i <= amount; i++) {
            for (int coin : coins) {
                if (i >= coin) {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }
        
        return dp[amount] > amount ? -1 : dp[amount];
    }
    
    // Top-down memoization
    int coinChangeRecursive(vector<int>& coins, int amount) {
        vector<int> memo(amount + 1, -1);
        int result = helper(coins, amount, memo);
        return result == INT_MAX ? -1 : result;
    }
    
private:
    int helper(vector<int>& coins, int amount, vector<int>& memo) {
        if (amount == 0) return 0;
        if (amount < 0) return INT_MAX;
        if (memo[amount] != -1) return memo[amount];
        
        int minCoins = INT_MAX;
        for (int coin : coins) {
            int subResult = helper(coins, amount - coin, memo);
            if (subResult != INT_MAX) {
                minCoins = min(minCoins, subResult + 1);
            }
        }
        
        memo[amount] = minCoins;
        return minCoins;
    }
};
```

**Key Insights:**
- `dp[i]` = minimum coins needed to make amount `i`
- Transition: `dp[i] = min(dp[i], dp[i-coin] + 1)`
- Time: O(amount × coins), Space: O(amount)

### **2. Coin Change II - Count Ways**
**Problem**: Count number of ways to make target amount.

```cpp
class CoinChangeII {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;  // One way to make 0: use no coins
        
        // Process each coin type
        for (int coin : coins) {
            // Update dp array for current coin
            for (int i = coin; i <= amount; i++) {
                dp[i] += dp[i - coin];
            }
        }
        
        return dp[amount];
    }
    
    // 2D DP version for clarity
    int change2D(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));
        
        // Base case: one way to make amount 0
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= amount; j++) {
                // Don't use current coin
                dp[i][j] = dp[i-1][j];
                
                // Use current coin (if possible)
                if (j >= coins[i-1]) {
                    dp[i][j] += dp[i][j - coins[i-1]];  // Note: dp[i], not dp[i-1]
                }
            }
        }
        
        return dp[n][amount];
    }
};
```

**Key Differences from Coin Change I:**
- We're counting ways, not minimizing
- Process coins in outer loop to avoid counting permutations
- `dp[i] += dp[i-coin]` (addition, not minimum)

---

## 🎯 Problem Variations

### **3. Perfect Squares**
```cpp
int numSquares(int n) {
    vector<int> dp(n + 1, n);  // Worst case: all 1s
    dp[0] = 0;
    
    // Generate perfect squares up to n
    vector<int> squares;
    for (int i = 1; i * i <= n; i++) {
        squares.push_back(i * i);
    }
    
    // Apply coin change pattern
    for (int i = 1; i <= n; i++) {
        for (int square : squares) {
            if (i >= square) {
                dp[i] = min(dp[i], dp[i - square] + 1);
            }
        }
    }
    
    return dp[n];
}
```

### **4. Combination Sum IV (Permutations)**
```cpp
int combinationSum4(vector<int>& nums, int target) {
    vector<unsigned int> dp(target + 1, 0);
    dp[0] = 1;
    
    // Note: target in outer loop to count permutations
    for (int i = 1; i <= target; i++) {
        for (int num : nums) {
            if (i >= num) {
                dp[i] += dp[i - num];
            }
        }
    }
    
    return dp[target];
}
```

**Key Insight**: Loop order determines if we count combinations or permutations!

### **5. Coin Change with Limited Supply**
```cpp
int coinChangeLimited(vector<int>& coins, vector<int>& counts, int amount) {
    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;
    
    for (int i = 0; i < coins.size(); i++) {
        int coin = coins[i];
        int count = counts[i];
        
        // Process from right to left to avoid using same coin multiple times
        for (int j = amount; j >= coin; j--) {
            // Try using 1, 2, ..., count coins of current type
            for (int k = 1; k <= count && j >= k * coin; k++) {
                if (dp[j - k * coin] != amount + 1) {
                    dp[j] = min(dp[j], dp[j - k * coin] + k);
                }
            }
        }
    }
    
    return dp[amount] > amount ? -1 : dp[amount];
}
```

---

## 🚀 Advanced Patterns

### **1. State Machine DP**
For problems with state transitions (buy/sell stocks, etc.)

```cpp
// Stock with cooldown
int maxProfitWithCooldown(vector<int>& prices) {
    int n = prices.size();
    if (n <= 1) return 0;
    
    // States: hold[i] = max profit when holding stock on day i
    //         sold[i] = max profit when sold stock on day i
    //         rest[i] = max profit when resting on day i
    
    vector<int> hold(n), sold(n), rest(n);
    
    hold[0] = -prices[0];  // Buy on day 0
    sold[0] = 0;           // Can't sell on day 0
    rest[0] = 0;           // Rest on day 0
    
    for (int i = 1; i < n; i++) {
        hold[i] = max(hold[i-1], rest[i-1] - prices[i]);  // Hold or buy
        sold[i] = hold[i-1] + prices[i];                  // Sell
        rest[i] = max(rest[i-1], sold[i-1]);              // Rest
    }
    
    return max(sold[n-1], rest[n-1]);  // Can't hold at the end
}
```

### **2. Interval DP**
For problems involving ranges or intervals.

```cpp
// Matrix Chain Multiplication
int matrixChainOrder(vector<int>& dimensions) {
    int n = dimensions.size() - 1;  // Number of matrices
    vector<vector<int>> dp(n, vector<int>(n, 0));
    
    // l is chain length
    for (int l = 2; l <= n; l++) {
        for (int i = 0; i <= n - l; i++) {
            int j = i + l - 1;
            dp[i][j] = INT_MAX;
            
            // Try all possible split points
            for (int k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k+1][j] + 
                          dimensions[i] * dimensions[k+1] * dimensions[j+1];
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }
    
    return dp[0][n-1];
}
```

### **3. Digit DP**
For problems involving number properties.

```cpp
// Count numbers with specific digit properties
class DigitDP {
private:
    vector<vector<int>> memo;
    string num;
    
public:
    int countNumbers(int n) {
        num = to_string(n);
        memo.assign(num.size(), vector<int>(2, -1));
        return solve(0, true);
    }
    
private:
    int solve(int pos, bool tight) {
        if (pos == num.size()) return 1;
        
        if (memo[pos][tight] != -1) return memo[pos][tight];
        
        int limit = tight ? (num[pos] - '0') : 9;
        int result = 0;
        
        for (int digit = 0; digit <= limit; digit++) {
            // Add your digit constraints here
            bool newTight = tight && (digit == limit);
            result += solve(pos + 1, newTight);
        }
        
        return memo[pos][tight] = result;
    }
};
```

---

## ⚡ Optimization Techniques

### **1. Space Optimization**
```cpp
// Coin Change with O(amount) space instead of O(coins × amount)
int coinChangeSpaceOptimized(vector<int>& coins, int amount) {
    vector<int> prev(amount + 1, amount + 1);
    vector<int> curr(amount + 1, amount + 1);
    
    prev[0] = curr[0] = 0;
    
    for (int coin : coins) {
        for (int i = 1; i <= amount; i++) {
            curr[i] = prev[i];  // Don't use current coin
            if (i >= coin) {
                curr[i] = min(curr[i], curr[i - coin] + 1);  // Use current coin
            }
        }
        prev = curr;
    }
    
    return curr[amount] > amount ? -1 : curr[amount];
}
```

### **2. Early Termination**
```cpp
int coinChangeEarlyExit(vector<int>& coins, int amount) {
    if (amount == 0) return 0;
    
    sort(coins.rbegin(), coins.rend());  // Sort in descending order
    
    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;
    
    for (int i = 1; i <= amount; i++) {
        for (int coin : coins) {
            if (coin > i) continue;  // Skip coins larger than current amount
            if (dp[i - coin] == amount + 1) continue;  // Skip impossible states
            
            dp[i] = min(dp[i], dp[i - coin] + 1);
            
            if (dp[i] == 1) break;  // Can't get better than 1 coin
        }
    }
    
    return dp[amount] > amount ? -1 : dp[amount];
}
```

---

## 🎯 Interview Strategy

### **Problem Identification Checklist:**
- [ ] **Optimization problem** (min/max/count)
- [ ] **Multiple choices** at each step
- [ ] **Overlapping subproblems**
- [ ] **Unlimited use** of items (unbounded knapsack)

### **Solution Template:**
```cpp
// 1. Define state
// dp[i] = optimal value for amount i

// 2. Initialize base cases
vector<int> dp(amount + 1, defaultValue);
dp[0] = baseCase;

// 3. Fill DP table
for (each coin/item) {
    for (int i = coin; i <= amount; i++) {
        dp[i] = optimize(dp[i], dp[i - coin] + cost);
    }
}

// 4. Return result
return dp[amount];
```

### **Common Pitfalls:**
1. **Wrong initialization**: Use impossible values for min problems
2. **Loop order**: Affects whether you count combinations vs permutations
3. **Boundary checks**: Ensure `i >= coin` before accessing `dp[i - coin]`
4. **Integer overflow**: Use appropriate data types for counting problems

### **Complexity Analysis:**
- **Time**: O(amount × coins) for most coin change variants
- **Space**: O(amount) with optimization, O(amount × coins) for 2D DP

---

## 🏆 Advanced Applications

### **1. Knapsack Variants**
```cpp
// Unbounded Knapsack (Coin Change generalization)
int unboundedKnapsack(vector<int>& weights, vector<int>& values, int capacity) {
    vector<int> dp(capacity + 1, 0);
    
    for (int i = 0; i < weights.size(); i++) {
        for (int w = weights[i]; w <= capacity; w++) {
            dp[w] = max(dp[w], dp[w - weights[i]] + values[i]);
        }
    }
    
    return dp[capacity];
}
```

### **2. Probability DP**
```cpp
// Soup Servings problem
double soupServings(int n) {
    // Memoization map
    unordered_map<long long, double> memo;
    
    function<double(int, int)> solve = [&](int a, int b) -> double {
        if (a <= 0 && b <= 0) return 0.5;  // Both empty simultaneously
        if (a <= 0) return 1.0;            // A empty first
        if (b <= 0) return 0.0;            // B empty first
        
        long long key = ((long long)a << 32) | b;
        if (memo.count(key)) return memo[key];
        
        double result = 0.25 * (
            solve(a - 100, b) +        // Serve 100ml A, 0ml B
            solve(a - 75, b - 25) +    // Serve 75ml A, 25ml B
            solve(a - 50, b - 50) +    // Serve 50ml A, 50ml B
            solve(a - 25, b - 75)      // Serve 25ml A, 75ml B
        );
        
        return memo[key] = result;
    };
    
    return solve(n, n);
}
```

---

## 🎮 Practice Progression

### **Level 1: Basic Coin Change**
1. Coin Change (minimum coins)
2. Coin Change II (count ways)
3. Perfect Squares

### **Level 2: Variations**
4. Combination Sum IV
5. Coin Change with limited supply
6. Minimum cost for tickets

### **Level 3: Advanced Patterns**
7. Best Time to Buy/Sell Stock with Cooldown
8. Stone Game variations
9. Soup Servings

---

*Master the coin change pattern and you'll unlock a whole family of DP problems! 💰*
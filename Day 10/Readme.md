# 🎯 Day 10: Binary Search on Answer - Advanced Pattern

## 📚 Table of Contents
1. [What is Binary Search on Answer?](#what-is-binary-search-on-answer)
2. [Core Pattern Template](#core-pattern-template)
3. [Problem Examples](#problem-examples)
4. [Advanced Techniques](#advanced-techniques)
5. [Interview Strategy](#interview-strategy)

---

## 🤔 What is Binary Search on Answer?

**Binary Search on Answer** is a powerful technique where we binary search on the **answer space** rather than searching through an array. Instead of finding an element, we're finding the optimal value that satisfies certain conditions.

### **Key Characteristics:**
- ✅ **Answer has a range**: min_answer ≤ answer ≤ max_answer
- ✅ **Monotonic property**: If answer X works, then all answers ≥ X also work (or vice versa)
- ✅ **Checking function**: We can verify if a given answer is feasible in reasonable time
- ✅ **Optimization**: We want the minimum/maximum feasible answer

### **When to Use:**
- "Find minimum/maximum value such that..."
- "What's the smallest/largest X where condition Y holds?"
- The answer has a clear range and monotonic property

---

## 💻 Core Pattern Template

### **Standard Template:**
```cpp
class BinarySearchOnAnswer {
public:
    // Generic template for binary search on answer
    int binarySearchOnAnswer(int left, int right, function<bool(int)> canAchieve) {
        int result = -1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (canAchieve(mid)) {
                result = mid;           // Store current answer
                right = mid - 1;       // Try to find smaller answer
            } else {
                left = mid + 1;        // Need larger answer
            }
        }
        
        return result;
    }
    
    // For finding maximum answer
    int binarySearchMaxAnswer(int left, int right, function<bool(int)> canAchieve) {
        int result = -1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (canAchieve(mid)) {
                result = mid;           // Store current answer
                left = mid + 1;        // Try to find larger answer
            } else {
                right = mid - 1;       // Need smaller answer
            }
        }
        
        return result;
    }
};
```

### **Problem-Solving Framework:**
1. **Identify the answer space**: What are we optimizing? What's the range?
2. **Check monotonicity**: If answer X works, do all larger/smaller X also work?
3. **Implement checking function**: Can we verify if answer X is feasible?
4. **Apply binary search**: Search for optimal answer in the valid range

---

## 🎯 Problem Examples

### **1. Koko Eating Bananas**
**Problem**: Find minimum eating speed to finish all bananas in H hours.

```cpp
class KokoEatingBananas {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;                              // Minimum possible speed
        int right = *max_element(piles.begin(), piles.end());  // Maximum possible speed
        
        return binarySearchOnAnswer(left, right, [&](int speed) {
            return canFinishInTime(piles, h, speed);
        });
    }
    
private:
    bool canFinishInTime(vector<int>& piles, int h, int speed) {
        long long totalHours = 0;
        
        for (int pile : piles) {
            totalHours += (pile + speed - 1) / speed;  // Ceiling division
            if (totalHours > h) return false;           // Early termination
        }
        
        return totalHours <= h;
    }
    
    int binarySearchOnAnswer(int left, int right, function<bool(int)> canAchieve) {
        int result = right;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (canAchieve(mid)) {
                result = mid;
                right = mid - 1;  // Try smaller speed
            } else {
                left = mid + 1;   // Need faster speed
            }
        }
        
        return result;
    }
};
```

**Key Insights:**
- Answer range: [1, max(piles)]
- Monotonic: If speed X works, speed X+1 also works
- Check function: Calculate total hours needed

### **2. Capacity to Ship Packages Within D Days**
```cpp
class ShipPackages {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left = *max_element(weights.begin(), weights.end());  // Min capacity
        int right = accumulate(weights.begin(), weights.end(), 0); // Max capacity
        
        return binarySearchOnAnswer(left, right, [&](int capacity) {
            return canShipInDays(weights, days, capacity);
        });
    }
    
private:
    bool canShipInDays(vector<int>& weights, int days, int capacity) {
        int daysNeeded = 1;
        int currentLoad = 0;
        
        for (int weight : weights) {
            if (currentLoad + weight > capacity) {
                daysNeeded++;
                currentLoad = weight;
                
                if (daysNeeded > days) return false;
            } else {
                currentLoad += weight;
            }
        }
        
        return true;
    }
    
    int binarySearchOnAnswer(int left, int right, function<bool(int)> canAchieve) {
        int result = right;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (canAchieve(mid)) {
                result = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        return result;
    }
};
```

### **3. Minimum Number of Days to Make m Bouquets**
```cpp
class MinDaysForBouquets {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if ((long long)m * k > bloomDay.size()) return -1;
        
        int left = *min_element(bloomDay.begin(), bloomDay.end());
        int right = *max_element(bloomDay.begin(), bloomDay.end());
        
        return binarySearchOnAnswer(left, right, [&](int days) {
            return canMakeBouquets(bloomDay, m, k, days);
        });
    }
    
private:
    bool canMakeBouquets(vector<int>& bloomDay, int m, int k, int days) {
        int bouquets = 0;
        int consecutive = 0;
        
        for (int day : bloomDay) {
            if (day <= days) {
                consecutive++;
                if (consecutive == k) {
                    bouquets++;
                    consecutive = 0;
                    
                    if (bouquets >= m) return true;
                }
            } else {
                consecutive = 0;
            }
        }
        
        return bouquets >= m;
    }
    
    int binarySearchOnAnswer(int left, int right, function<bool(int)> canAchieve) {
        int result = -1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (canAchieve(mid)) {
                result = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        return result;
    }
};
```

---

## 🚀 Advanced Techniques

### **1. Floating Point Binary Search**
For problems involving real numbers:

```cpp
double binarySearchFloat(double left, double right, function<bool(double)> canAchieve) {
    const double EPS = 1e-9;
    
    while (right - left > EPS) {
        double mid = left + (right - left) / 2.0;
        
        if (canAchieve(mid)) {
            right = mid;  // For minimum
            // left = mid;  // For maximum
        } else {
            left = mid;   // For minimum
            // right = mid; // For maximum
        }
    }
    
    return left;  // or right, they're approximately equal
}
```

### **2. Discrete vs Continuous Spaces**
```cpp
// For discrete space (integers)
int binarySearchDiscrete(int left, int right, function<bool(int)> canAchieve) {
    while (left < right) {
        int mid = left + (right - left) / 2;
        
        if (canAchieve(mid)) {
            right = mid;      // mid could be the answer
        } else {
            left = mid + 1;   // mid is definitely not the answer
        }
    }
    
    return left;
}

// For continuous space (floating point)
double binarySearchContinuous(double left, double right, function<bool(double)> canAchieve) {
    for (int iter = 0; iter < 100; iter++) {  // Fixed iterations
        double mid = left + (right - left) / 2.0;
        
        if (canAchieve(mid)) {
            right = mid;
        } else {
            left = mid;
        }
    }
    
    return left;
}
```

### **3. Multi-dimensional Binary Search**
```cpp
// Example: Find minimum ratio where condition holds
pair<int, int> binarySearchRatio(vector<pair<int, int>>& items, function<bool(double)> canAchieve) {
    // Binary search on the slope of possible ratios
    vector<pair<double, pair<int, int>>> slopes;
    
    for (int i = 0; i < items.size(); i++) {
        for (int j = i + 1; j < items.size(); j++) {
            if (items[j].second != items[i].second) {
                double slope = (double)(items[j].first - items[i].first) / 
                              (items[j].second - items[i].second);
                slopes.push_back({slope, {i, j}});
            }
        }
    }
    
    sort(slopes.begin(), slopes.end());
    
    int left = 0, right = slopes.size() - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (canAchieve(slopes[mid].first)) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    return slopes[left].second;
}
```

---

## 🎯 Interview Strategy

### **Problem Recognition:**
Look for these patterns:
- "Find minimum X such that..."
- "What's the maximum Y where..."
- "Minimize the maximum" or "Maximize the minimum"
- Clear range of possible answers
- Expensive to check all possibilities

### **Step-by-Step Approach:**
1. **Identify what to binary search on**
   - What are we optimizing?
   - What's the search space?

2. **Determine the bounds**
   - Minimum possible answer
   - Maximum possible answer

3. **Check monotonicity**
   - If answer X works, what about X±1?
   - Which direction should we search?

4. **Implement feasibility check**
   - Given an answer, can we verify if it's valid?
   - Keep this function efficient!

5. **Choose search direction**
   - Minimize: if mid works, search smaller values
   - Maximize: if mid works, search larger values

### **Common Patterns:**

#### **Pattern 1: Resource Allocation**
- Koko eating bananas (time allocation)
- Ship packages (capacity allocation)
- Split array (sum allocation)

#### **Pattern 2: Rate/Speed Problems**
- Minimum speed to finish task
- Maximum rate while satisfying constraints

#### **Pattern 3: Threshold Problems**
- Find minimum threshold for condition
- Maximum value before condition fails

### **Implementation Checklist:**
```cpp
// 1. Define search bounds carefully
int left = minPossibleAnswer;
int right = maxPossibleAnswer;

// 2. Handle edge cases
if (impossible_condition) return -1;

// 3. Implement efficient check function
bool canAchieve(int answer) {
    // Should be O(n) or O(n log n) at most
    // Return true if answer is feasible
}

// 4. Choose correct search direction
if (canAchieve(mid)) {
    result = mid;
    // For minimum: right = mid - 1
    // For maximum: left = mid + 1
} else {
    // For minimum: left = mid + 1
    // For maximum: right = mid - 1
}
```

### **Time Complexity:**
- **Search iterations**: O(log(answer_range))
- **Check function**: Depends on problem (usually O(n))
- **Total**: O(n * log(answer_range))

---

## 🏆 Advanced Applications

### **1. Aggressive Cows (Distance Maximization)**
```cpp
int maxMinDistance(vector<int>& stalls, int cows) {
    sort(stalls.begin(), stalls.end());
    
    int left = 1;  // Minimum possible distance
    int right = stalls.back() - stalls[0];  // Maximum possible distance
    
    return binarySearchOnAnswer(left, right, [&](int minDist) {
        return canPlaceCows(stalls, cows, minDist);
    });
}

bool canPlaceCows(vector<int>& stalls, int cows, int minDist) {
    int placed = 1;
    int lastPos = stalls[0];
    
    for (int i = 1; i < stalls.size(); i++) {
        if (stalls[i] - lastPos >= minDist) {
            placed++;
            lastPos = stalls[i];
            
            if (placed >= cows) return true;
        }
    }
    
    return false;
}
```

### **2. Median of Two Sorted Arrays**
```cpp
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    if (nums1.size() > nums2.size()) {
        return findMedianSortedArrays(nums2, nums1);
    }
    
    int m = nums1.size(), n = nums2.size();
    int left = 0, right = m;
    
    while (left <= right) {
        int partitionX = left + (right - left) / 2;
        int partitionY = (m + n + 1) / 2 - partitionX;
        
        int maxLeftX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
        int minRightX = (partitionX == m) ? INT_MAX : nums1[partitionX];
        
        int maxLeftY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];
        int minRightY = (partitionY == n) ? INT_MAX : nums2[partitionY];
        
        if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
            if ((m + n) % 2 == 0) {
                return (max(maxLeftX, maxLeftY) + min(minRightX, minRightY)) / 2.0;
            } else {
                return max(maxLeftX, maxLeftY);
            }
        } else if (maxLeftX > minRightY) {
            right = partitionX - 1;
        } else {
            left = partitionX + 1;
        }
    }
    
    return 0.0;
}
```

---

## 🎮 Practice Progression

### **Level 1: Basic Patterns**
1. Koko Eating Bananas
2. Capacity to Ship Packages
3. Find Peak Element

### **Level 2: Intermediate**
4. Minimum Days for Bouquets
5. Split Array Largest Sum
6. Minimize Max Distance to Gas Station

### **Level 3: Advanced**
7. Aggressive Cows
8. Median of Two Sorted Arrays
9. Minimize the Maximum Difference

---

*Master Binary Search on Answer and you'll be able to optimize solutions to many seemingly complex problems! 🎯*
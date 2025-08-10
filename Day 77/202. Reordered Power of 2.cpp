class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string digits = to_string(n);
        sort(digits.begin(), digits.end()); // For duplicate skipping
         vector<bool> used(digits.size(), false); //A boolean array that tracks which positions in digits have been used in the current permutation
        return backtrack(digits, used, ""); //Start the recursion with an empty curr string. If any permutation yields a power of two, we return true
    }
    bool backtrack(string &digits, vector<bool> &used, string curr) {
        if (curr.size() == digits.size()) {
            if (curr[0] == '0') 
                return false; // Reject permutations with a leading zero
            long long num = stoll(curr);
            return isPowerOfTwo(num);
        }
        for (int i = 0; i < digits.size(); i++) 
        { //Iterate over each digit position to try placing that digit next in the permutation.
            if (used[i]) //If this digit is already used in the current partial permutation, skip it.
              continue;
            // Skip duplicates: if same digit as prev and prev not used, skip
            if (i > 0 && digits[i] == digits[i-1] && !used[i-1]) 
                continue;
            used[i] = true;
            curr.push_back(digits[i]);
            if (backtrack(digits, used, curr)) 
                return true; //Recurse: if any deeper recursion returns true (we found a valid permutation), return true immediately (early exit / short-circuit). This is important for speed — we stop as soon as we know the answer is true
            curr.pop_back(); //undo
            used[i] = false;
        }
        return false; //no valid permutation was found from this branch.
    }
    bool isPowerOfTwo(long long num) {
        return num > 0 && (num & (num - 1)) == 0;
      //Bit trick: a positive number is a power of two iff it has exactly one 1 bit. The expression num & (num - 1) clears the lowest set bit; if result is 0 and num > 0, num was a power of two.
    }
};

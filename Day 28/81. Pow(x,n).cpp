class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        if (x==1)
            return 1;
        if (n == 0)
            return 1;
        long long pow=n;
        if (n > 0) {
            for (long long i = 1; i <= pow; i++) {
                ans *= x;
            }
            return ans;
        }
        for (long long i = pow; i < 0; i++) {
            ans *= x;
        }
        return 1.0 / ans;
    }
};
//TC o(N)
//SC O(1)

class Solution 
{
public:
    double myPow(double x, int n) 
    {
        if (x == 1 || n == 0) 
            return 1;
        if (x == 0) 
            return 0;
        return helper(x, n);
    }
    double helper(double x, long long n) 
    {
        if (n == 1) 
            return x;
        if (n == -1) 
            return 1.0 / x;
        double var = helper(x, n / 2);
        if (n % 2 == 0) //even power
        {
            return var * var;
        } 
        else //odd power
        {
            if (n > 0)
                return var * var * x;
            else
                return var * var * (1.0/x);
        }
    }
};
//TC O(logn)
//SC O(logn)

class Solution 
{
    unordered_map<long long, double> dp; // memoization map
public:
    double myPow(double x, int n) 
    {
        if (x == 1 || n == 0) 
            return 1;
        if (x == 0) 
            return 0;
        return helper(x, (long long)n); // cast to long long to handle INT_MIN
    }
    double helper(double x, long long n) 
    {
        if (n == 0) 
            return 1;
        if (n == 1) 
            return x;
        if (n == -1) 
            return 1.0 / x;
        // Check if already computed
        if (dp.find(n) != dp.end()) 
            return dp[n];
        // Divide and conquer with memoization
        double half = helper(x, n / 2);
        if (n % 2 == 0)
            return dp[n] = half * half;
        else {
            if (n > 0)
                return dp[n] = half * half * x;
            else
                return dp[n] = half * half * (1.0 / x);
        }
    }
};
//TC O(logn)
//SC O(logn)

class Solution 
{
public:
    unordered_set<int> seen;
    bool isHappy(int n) 
    {
        while (1) //run until true or false is returned
        {
            int square = 0;
            while (n != 0) 
            {
                int digit = n % 10;
                square += (digit * digit);
                n = n / 10;
            }
            if (square == 1)
                return true;
            if (seen.count(square) > 0) //if square was an answer in any previous iteration
            {
                return false;
            }
            seen.insert(square); //for future use
            n=square;
        }
        return true; //for next iteration
    }
};

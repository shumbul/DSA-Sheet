class Solution 
{
public:
    vector<int> asteroidCollision(vector<int>& asteroids) 
{
        stack<int> stk;
        for (int ast : asteroids) 
        {
            bool destroyed = false;
            // Handle collisions
            while (!stk.empty() && stk.top() > 0 && ast < 0) //when a right-moving asteroid on the stack meets a left-moving asteroid
            {
                if (abs(stk.top()) < abs(ast)) 
                {
                    stk.pop();  // Smaller asteroid on stack destroyed
                    continue;
                } 
                else if (abs(stk.top()) == abs(ast)) 
                {
                    stk.pop();  // Both destroy each other
                    destroyed = true;
                    break;
                } 
                else 
                {
                    destroyed = true;  // Current asteroid destroyed
                    break;
                }
            }
            if (!destroyed) 
            {
                stk.push(ast); //if the current asteroid wasn't destroyed
            }
        }
        // Build result from stack
        vector<int> result(stk.size());
        for (int i = stk.size() - 1; i >= 0; --i) 
        {
            result[i] = stk.top();
            stk.pop();
        }
        return result;
    }
};
//TC O(N)
//SC O(N)

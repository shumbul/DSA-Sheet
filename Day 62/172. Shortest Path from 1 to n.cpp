// User function Template for C++

class Solution {
  public:
    int minimumStep(int n) {
        // complete the function here
        queue<int> traverse;
        int ans=0, count=0;
        traverse.push(1);
        while (!traverse.empty())
        {
            int frontt=traverse.front();
            //cout<<"frontt"<<frontt<<endl;
            traverse.pop();
            if (frontt*3<=n)
            {
                traverse.push(frontt*3);
                count++;
            }
            else if (frontt+1<=n)
            {
                traverse.push(frontt+1);
                count++;
            }
        }
        return count;
    }
};

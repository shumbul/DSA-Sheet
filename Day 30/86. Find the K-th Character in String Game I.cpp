class Solution {
     string ans="a"; //holds the growing sequence of chars
      queue<char> temp; //temporarily store chars
public:
    char kthCharacter(int k) {
        temp.push('a');
        while (ans.size()<k) //we have built string to return the kth char
        {
            helper();
        }
        return ans[k-1];
    }
    void helper()
    {
        while (temp.size()>0)
        {
            char ch=temp.front();
            ans.push_back(ch+1);
            temp.pop();
        }
        for (int i=0;i<ans.size();i++)
        {
            temp.push(ans[i]); //prepares temp for the next call
        }
    }
};
//TC O(N)
//SC O(N)

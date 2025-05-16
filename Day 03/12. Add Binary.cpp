class Solution 
{
public:
    string addBinary(string a, string b) 
    {
        string ans;
        char carry = '0';
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        if (a.size() > b.size()) 
        {
            ans = a;
            while (a.size()>b.size()) 
            {
                b = b + '0';
            }
        } 
        else 
        {
            ans = b;
            while (a.size()<b.size()) 
            {
                a = a + '0';
            }
        }
        for (int i = 0; i < min(a.size(), b.size()); i++) 
        {
            if (carry == '0') 
            {
                if (a[i] == '0' && b[i] == '0')
                    ans[i] = '0';
                else if (a[i] == '0' && b[i] == '1') 
                    ans[i] = '1';
                else if (a[i] == '1' && b[i] == '0')
                    ans[i] = '1';
                else 
                {
                    ans[i] = '0';
                    carry = '1';
                }
            } 
            else 
            {
                if (a[i] != b[i]) 
                {
                    ans[i] = '0';
                    carry = '1';
                } 
                else if (a[i] == '0' && b[i] == '0') 
                {
                    ans[i] = '1';
                    carry = '0';
                } 
                else 
                {
                    ans[i] = '1';
                    carry = '1';
                }
            }
        }
        if (carry == '1')
            ans = ans + carry;
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
//TC O(N)
//SC O(N)

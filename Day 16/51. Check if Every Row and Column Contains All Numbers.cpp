class Solution 
{
public:
    bool checkValid(vector<vector<int>>& matrix) 
    {
        int n=matrix.size();
        int sumrow=0; //sum of a row
        int sum=0; //expected sum of 1 to n
        for (int i=1;i<=n;i++)
        {
            sum+=i;
        }
        for (int i=0;i<n;i++)
        {
            set<int> freq; //track unique elements in a row
            for (int j=0;j<n;j++)
            {
                sumrow+=matrix[i][j];
                freq.insert(matrix[i][j]);
            }
            if (sumrow!=sum || freq.size()!=n) //if not valid
                return false;
            sumrow=0;
        }
        for (int i=0;i<n;i++) //same procedure for columns
        {
            for (int j=0;j<n;j++)
            {
                sumrow+=matrix[j][i];
            }
            if (sumrow!=sum)
                return false;
            sumrow=0;
        }
        return true;
    }
};
//TC O(n^2)
//SC O(n)

class Solution 
{
public:
    bool checkValid(vector<vector<int>>& matrix) 
    {
        int n=matrix.size();
        int sumrow=0; //track row sum
        int sumcol=0; //track column sum
        int sum=0; //expected sum of 1 to n
        
        for (int i=1;i<=n;i++)
        {
            sum+=i;
        }
        for (int i=0;i<n;i++)
        {
            set<int> freq; //track unique elements in row i
            for (int j=0;j<n;j++)
            {
                sumrow+=matrix[i][j];
                sumcol+=matrix[j][i];
                freq.insert(matrix[i][j]); //check row uniqueness
            }
            
            if (sumrow!=sum || freq.size()!=n || sumcol!=sum)
                return false;
            sumrow=0;
            sumcol=0;
        }
        return true;
    }
};
//TC O(n^2)
//SC O(n)


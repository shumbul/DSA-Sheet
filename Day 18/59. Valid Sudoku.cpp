class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i=0;i<9;i++)
        {
            for (int j=0;j<9;j++)
            {
                if (board[i][j]!='.')
                {
                    for (int k=i+1;k<9;k++) //if any same value exists below in the same col
                    {
                        if (board[k][j]==board[i][j])
                        {
                            return false;
                        }
                    }
                    for (int l=j+1;l<9;l++) //if any same value exists to the right in the same row 
                    {
                        if (board[i][l]==board[i][j])
                        {
                            return false;
                        }
                    }
                }
            }
        }
        for (int i=0;i<9;i+=3) //loops over every 3×3 subgrid starting at (0,0), (0,3), (0,6), (3,0), etc
        {
            for (int j=0;j<9;j+=3)
            {
               if (helper(i,j, board)==false)
                return false;
            }
        }
        
        return true;
    }
    bool helper(int i, int j, vector<vector<char>>& board)
    //checks in 3x3 box and if there are any duplicates it returns false else returns true
    {
        for (int k=i;k<i+3;k++) //for every (k,l) in the 3×3 subgrid, it checks every other (a,b) in the same subgrid
        {
            for (int l=j;l<j+3;l++)
            {
                for (int a=i;a<i+3 && a<9;a++)
                {
                    for (int b=j;b<j+3 && b<9;b++)
                    {
                        if (a==k && l==b) //if we are checking same box
                            continue;
                        if (board[a][b]==board[k][l] && board[a][b]!='.')
                            return false;
                    }
                }
            }
        }
        return true;
    }
};

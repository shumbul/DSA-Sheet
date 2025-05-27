class Solution 
{
public:
    void setZeroes(vector<vector<int>>& matrix) 
    {
        int m=matrix.size(); //no. of rows
        int n=matrix[0].size(); //no. of columns
	    vector<int> rows(m,1); //size m initialized to 1 indicating no zeroes initially
        vector<int> cols(n,1); ////size n initialized to 1 indicating no zeroes initially
	    for(int i=0;i<m;i++)
	    {
	    	for(int j=0;j<n;j++)
		    {
		    	if(matrix[i][j]==0)
			    {
				    rows[i]=0; //mark row i to be zeroed
				    cols[j]=0; //mark column j to be zeroed
			    }
		    }
	    }
	    for(int i=0;i<m;i++)
	    {
		    for(int j=0;j<n;j++)
		    {
			    if(rows[i]==0 || cols[j]==0)
			    {
				    matrix[i][j]=0; //zero that cell
			    }
		    }
	    }
    }
};
//TC O(nm)
//SC O(n+m)

class Solution 
{
public:
    void setZeroes(vector<vector<int>>& matrix) 
    {
       bool cols=1; //to track if 1st col needs to be zeroed
	    int m=matrix.size(); //no. of rows
        int n=matrix[0].size(); //no. of cols
	    for(int i=0;i<m;i++)
	    {
		    for(int j=0;j<n;j++)
		    {
			    if(matrix[i][j]==0)
			    {
				    matrix[i][0]=0; //mark row i using 1st col
				    if (j!=0)
					    matrix[0][j]=0; //mark col i using 1st row
				    else
					    cols=0; //for 1st col
			    }
		    }
	    }
	    for(int i=1;i<m;i++)
	    {
		    for(int j=1;j<n;j++)
		    {
			    if(matrix[i][j]!=0)
			    {
                    if (matrix[i][0] == 0 || matrix[0][j] == 0) 
				        matrix[i][j] = 0; //zero the cell
                }
            }
        }
	    if(matrix[0][0]==0) //1st row needs to be zeroed
	    {
		    for (int i = 0; i < n; i++) 
		    {
			    matrix[0][i] = 0;
		    }
        }
	    if(cols==0) //1st col needs to be zeroed
	    {
		    for (int j = 0; j < m; j++) 
		    {
			    matrix[j][0] = 0;
		    }
        }
    }
};
//TC O(M*N)
//SC O(1)

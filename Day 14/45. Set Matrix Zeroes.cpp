
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

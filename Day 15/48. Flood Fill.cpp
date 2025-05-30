class Solution {
    //directions
    int dx[4]={0,0,1,-1};
    int dy[4]={1,-1,0,0};
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) 
    {
        int original=image[sr][sc]; //store original colour
        if (image[sr][sc]==color) //if already correct colour
            return image;
        helper(image, original, sr, sc, color);
        return image;
    }
    void helper(vector<vector<int>>& image, int original, int sr, int sc, int color)
    {
        if (sr>=0 && sc>=0 && sr<image.size() && sc<image[0].size() && image[sr][sc]==original) //ensures (sr, sc) is within bounds and matches the original color
        {
            image[sr][sc]=color;
            for (int i=0;i<4;i++)
            //explores right, left, down, and up neighbors recursively
            {
                int newsr=sr+dx[i];
                int newsc=sc+dy[i];
                helper(image, original, newsr, newsc, color);
            }
        }
    }
};
//TC O(m*n)
//SC O(m*n)

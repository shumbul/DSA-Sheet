//DFS
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

//BFS
class Solution {
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    queue<pair<int, int>> nodes;
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int original = image[sr][sc];
        if (image[sr][sc] == color)
            return image;
        nodes.push({sr,sc});
        helper(image, original, color);
        return image;
    }
    void helper(vector<vector<int>>& image, int original, int color) {
        while (!nodes.empty()) {
            int frontx = nodes.front().first;
            int fronty = nodes.front().second;
            nodes.pop();
            if (fronty >= 0 && frontx >= 0 && frontx < image.size() &&
                fronty < image[0].size() && image[frontx][fronty] == original) {
                image[frontx][fronty] = color;
                for (int i = 0; i < 4; i++) {
                    int newi = frontx + dx[i];
                    int newj = fronty + dy[i];
                    nodes.push({newi, newj});
                }
            }
        }
    }
};

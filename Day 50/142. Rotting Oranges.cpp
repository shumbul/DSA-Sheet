//simulate rot spreading layer by layer, like a wave — that’s BFS.
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        queue<pair<int, int>> q;
        int fresh = 0, minutes = 0;
        // Step 1: Add all rotten oranges to the queue
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } 
                else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }
        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, 1, 0, -1};
        // Step 2: BFS
        while (!q.empty() && fresh > 0) {
            int sz = q.size(); //used to process one level (one minute) at a time.
            for (int i = 0; i < sz; i++) 
            { //Take each rotten orange at current level (minute) and process its neighbors.
                auto [x, y] = q.front();
                q.pop();
                for (int k = 0; k < 4; k++) {
                    int nx = x + dx[k];
                    int ny = y + dy[k];
                    if (nx >= 0 && ny >= 0 && nx < rows && ny < cols && grid[nx][ny] == 1) 
                    { //If neighbor is inside bounds and is a fresh orange, rot it:
                        grid[nx][ny] = 2;
                        q.push({nx, ny}); //for next round.
                        fresh--;
                    }
                }
            }
            minutes++; //1 minute has passed.
        }
        if (fresh==0)
            return minutes;
        return -1; //some fresh were unreachable
    }
};
//TC O(N*M)
//SC O(N*M)

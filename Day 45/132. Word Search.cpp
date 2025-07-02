class Solution {
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    bool ans = false;  //becomes true once the word is found
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0]) {
                    dfs(board, word, i, j, 0);
                    if (ans)
                        return true; //if ans is true in any DFS path, we return early
                }
            }
        }
        return ans;
    }
    void dfs(vector<vector<char>>& board, string& word, int row, int col,
             int pos) {
        if (ans)
            return; //early exit if word is already found
        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || board[row][col] != word[pos]) //character mismatch
            return;
        if (pos == word.size()-1) {
            ans = true;
            return;
        }
        board[row][col] = '*'; //Mark the current cell as visited
        for (int i = 0; i < 4; i++) {
            dfs(board, word, row + dx[i], col + dy[i], pos + 1);
        }
        board[row][col] = word[pos]; //Restore the cell's original character (backtrack) after exploring all paths
    }
};
//TC O(N*M*4^L)
//L=length of word
//SC O(L) recursion stack

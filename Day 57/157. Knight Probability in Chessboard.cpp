class Solution {
public:
    int totalNQueens(int n) {
        int count = 0;
        vector<string> board(n, string(n, '.'));
        findAns(0, count, board, n);
        return count;
    }
    void findAns(int col, int& count, vector<string>& board, int n) {
        if (col == n) {
            count++;
            return;
        }
        for (int row = 0; row < n; row++) {
            if (isSafe(row, col, board, n)) {
                board[row][col] = 'Q';
                findAns(col + 1, count, board, n);
                board[row][col] = '.';
            }
        }
    }
    bool isSafe(int row, int col, vector<string>& board, int n) {
        // Check left side of current row
        for (int i = col; i >= 0; i--) {
            if (board[row][i] == 'Q')
                return false;
        }
        // Check upper-left diagonal
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q')
                return false;
        }
        // Check lower-left diagonal
        for (int i = row, j = col; i < n && j >= 0; i++, j--) {
            if (board[i][j] == 'Q')
                return false;
        }
        return true;
    }
};

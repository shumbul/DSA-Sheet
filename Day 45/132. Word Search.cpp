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

//trie
class TrieNode {
public:
    TrieNode* children[26]; // Array for 26 lowercase letters a–z 
    char letter; // Stores the character this node represents
    bool isWord; // True if this node represents the end of a valid word
    unordered_map<char, TrieNode*> charnodes; // Maps a character to its child TrieNode
    TrieNode(char lett) {
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr; // Initializes children array
        }
        letter = lett;
        isWord = false;
    }
};
class Solution {
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    bool ans = false;
public:
    TrieNode* root = new TrieNode('0');
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();    // rows
        int m = board[0].size(); // cols
        insert(word);            // insert the word into the Trie
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // start DFS if board[i][j] matches the first character of word
                if (board[i][j] == word[0]) {
                    // only continue if path exists in Trie from this char
                    if (dfs(board, word, i, j, 0) &&
                        root->charnodes[board[i][j]])
                        return ans;
                }
            }
        }
        return ans;
    }
    bool dfs(vector<vector<char>>& board, string& word, int row, int col, int pos) {
        if (ans)
            return true; // early exit if already found
        // boundary and character check
        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || board[row][col] != word[pos])
            return false;
        // word completely matched
        if (pos == word.size() - 1) {
            ans = true;
            return ans;
        }
        board[row][col] = '*'; // mark as visited
        for (int i = 0; i < 4; i++) {
            dfs(board, word, row + dx[i], col + dy[i], pos + 1); // explore 4 directions
        }
        board[row][col] = word[pos]; // backtrack
        return true;
    }
    void insert(string word) {
        TrieNode* temp = root;
        for (int i = 0; i < word.size(); i++) {
            if (temp->charnodes.find(word[i]) == temp->charnodes.end()) {
                TrieNode* node = new TrieNode(word[i]);
                temp->charnodes[word[i]] = node;
            }
            temp = temp->charnodes[word[i]];
        }
        temp->isWord = true;
    }
};

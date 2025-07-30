class TrieNode {
public:
    TrieNode* children[26]; // Each index represents a character 'a' to 'z'
    bool isWord; // Marks if this node ends a word
    char letter; // Stores the full word at the end node
    TrieNode(char lett) {
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        isWord = false; // Initially not a word-end
        letter = lett;
    }
};
class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode('0'); // Initialize Trie with root node
    }
    void insert(string word) {
        TrieNode* temp = root;
        for (char ch : word) {
            if (temp->children[ch - 'a'] == nullptr) { // Create node if not exist
                temp->children[ch - 'a'] = new TrieNode(ch); 
            }
            temp = temp->children[ch - 'a']; // Move to the next character node
        }
        temp->isWord = true; // Mark the end of a word
        temp->word = word; // Store the complete word
    }
    void dfs(TrieNode* node, string& path, vector<string>& result) {
        if (result.size() == 3) 
            return;  // only top 3 suggestions
        if (node->isWord) {
            result.push_back(path); // Found a complete word
        }
        for (int i = 0; i < 26; i++) {
            if (node->children[i]) {
                path.push_back('a' + i);
                dfs(node->children[i], path, result);
                path.pop_back();
            }
        }
    }
    vector<string> wordsFromPrefix(string prefix) {
        TrieNode* temp = root;
        for (char ch : prefix) {
            if (temp->children[ch - 'a'] == nullptr) //If the character ch doesn't exist in the current Trie node’s children, it means the prefix doesn't exist
                return {};
            temp = temp->children[ch - 'a'];
        }
        vector<string> result;
        string path = prefix; //Initialize the current string path as the prefix itself. This will be built upon during DFS.
        dfs(temp, path, result); //Perform DFS starting from the node corresponding to the end of the prefix to collect full words.
        return result;
    }
};
class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Trie trie;
        sort(products.begin(), products.end()); // sort for lexicographical order
        for (string product : products) {
            trie.insert(product);
        }
        vector<vector<string>> ans;
        string prefix = "";
        for (char ch : searchWord) {
            prefix += ch;
            ans.push_back(trie.wordsFromPrefix(prefix)); //Fetch all products starting with this prefix and add to the result.
        }
        return ans;
    }
};

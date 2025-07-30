class TrieNode {
public:
    TrieNode* children[26]; // Each node has 26 possible children (a to z)
    char letter; // The character this node represents
    bool isWord; // Marks if this node ends a valid word
    TrieNode(char lett) {
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr; // Initialize all children to null
        }
        letter = lett; // Store the letter for debugging/tracking (optional)
        isWord = false; // Initially, this node doesn't mark the end of a word
    }
};
class Solution {
public:
    TrieNode* root = new TrieNode('0');  // Create a root node with dummy character '0'
    string longestWord(vector<string>& words) {
        string ans = "";
        sort(words.begin(), words.end()); // to ensure lexicographical order
        for (int i = 0; i < words.size(); i++) {
            if (insert(words[i])) 
            { //if it's valid and can be formed from smaller words already present in the Trie
                if (ans.size() + 1 == words[i].size()) //if it can be built by each char
                    ans = words[i];
            }
        }
        return ans;
    }
    bool insert(string word) {
        TrieNode* temp = root;
        for (int i = 0; i < word.size(); i++) {
            if (temp->children[word[i] - 'a'] == nullptr) {
                TrieNode* node = new TrieNode(word[i]);
                temp->children[word[i] - 'a'] = node;
            }
            temp = temp->children[word[i] - 'a'];
            if (i < word.size() - 1 && !temp->isWord) 
            //while building a word, If you are not at the last character Then the current prefix (temp) must be a valid word. If not, it means this current word can’t be built step-by-step from other valid words
                return false;
        }
        return temp->isWord = true;
    }
};

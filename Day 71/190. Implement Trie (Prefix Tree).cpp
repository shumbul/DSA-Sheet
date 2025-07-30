class TrieNode { //Defines the structure for each node in the trie.
public:
    TrieNode* children[26]; //An array of 26 pointers to child nodes
    char letter; //Stores the character that the node represents.
    bool isWord; //Marks whether the path from root to this node forms a complete word in the trie
    TrieNode(char lett) { //constructor
        for(int i=0;i<26;i++)
        {
            children[i]=nullptr;
        }
        letter = lett; //Assigns the character passed into the constructor to the node.
        isWord=false; //Marks that this node does not yet end a valid word.
    }
};
class Trie {
public:
    TrieNode* root = new TrieNode('0');
    Trie() {} //Default constructor for the Trie. Doesn’t need to do anything more because root is already initialized.
    void insert(string word) {
        TrieNode *temp=root; //Creates a root node with a dummy character '0'. It’s just a placeholder since the root doesn’t represent any letter.
        for (int i = 0; i < word.size(); i++) {
            if (temp->children[word[i]-'a'] == nullptr) 
            { //if the corresponding child node doesn't exist, create a new node
                TrieNode* node=new TrieNode(word[i]);
                temp->children[word[i]-'a']=node; //Assigns this new node to the correct child slot.
            }
                temp=temp->children[word[i]-'a']; //Move temp to the child node to continue the insertion.
        }
        temp->isWord=true;
    }
    bool search(string word) {
        TrieNode *temp=root;
        for (int i = 0; i < word.size(); i++) {
            if (temp->children[word[i]-'a'] == nullptr) 
            { //If the path breaks 
                return false;
            }
            temp=temp->children[word[i]-'a'];
        }
        return temp->isWord; //Only return true if the path exists and the final node is marked as a word.
    }
    bool startsWith(string prefix) {
        TrieNode *temp=root;
        for (int i = 0; i < prefix.size(); i++) {
            if (temp->children[prefix[i]-'a'] == nullptr) {
                return false;
            }
            temp=temp->children[prefix[i]-'a'];
        }
        return true;
    }
};

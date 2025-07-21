class Solution {
    unordered_set<char> currVisited;
    unordered_set<char> visited;
    unordered_map<char, unordered_set<char>> dict;
    string ans = "";
public:
    string findOrder(vector<string> &words) {
        // Ensure all characters are keys in dict
        for (const auto &word : words) {
            for (char c : word) {
                dict[c];  // this guarantees even isolated nodes are included
            }
        }
        // Build graph from differences between adjacent words
        for (int i = 0; i < words.size() - 1; i++) {
            for (int j = 0; j < min(words[i].size(), words[i + 1].size()); j++) {
                const string &w1 = words[i];
    const string &w2 = words[i + 1];
                if (w1.size() > w2.size() && w1.substr(0, w2.size()) == w2)
        return ""; //invalid prefix
                if (words[i][j] != words[i + 1][j]) {
                    dict[words[i][j]].insert(words[i + 1][j]);
                    break;
                }
            }
        }
        // DFS for topological sort
        for (auto &i : dict) {
            if (visited.find(i.first) == visited.end()) {
                if (!dfs(i.first))
                    return "";  // Cycle detected
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    bool dfs(char node) {
        if (currVisited.find(node) != currVisited.end())
            return false; // Cycle
        if (visited.find(node) != visited.end())
            return true; // Already processed
        currVisited.insert(node);
        for (auto nbr : dict[node]) {
            if (!dfs(nbr))
                return false;
        }
        currVisited.erase(node);
        visited.insert(node);
        ans += node;
        return true;
    }
};

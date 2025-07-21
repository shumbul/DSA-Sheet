//DFS
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

//BFS
class Solution {
public:
    string findOrder(vector<string>& words) {
        unordered_map<char, unordered_set<char>> graph;
        unordered_map<char, int> indegree;
        // Step 1: Initialize all characters in the graph
        for (const string& word : words) {
            for (char c : word) {
                graph[c];        // ensure key exists
                indegree[c] = 0; // initialize indegree
            }
        }
        // Step 2: Build the graph based on word differences
        for (int i = 0; i < words.size() - 1; i++) {
            string& w1 = words[i];
            string& w2 = words[i + 1];
            bool foundDifference = false;
            // Invalid prefix check (e.g., "abc" before "ab")
            if (w1.size() > w2.size() && w1.substr(0, w2.size()) == w2)
                return "";
            for (int j = 0; j < min(w1.size(), w2.size()); j++) {
                if (w1[j] != w2[j]) {
                    char u = w1[j], v = w2[j];
                    // Only add edge if not already added
                    if (graph[u].find(v) == graph[u].end()) {
                        graph[u].insert(v);
                        indegree[v]++;
                    }
                    break;
                }
            }
        }
        // Step 3: Topological sort using Kahn’s algorithm (BFS)
        queue<char> q;
        string ans;
        // Push all nodes with 0 indegree
        for (auto& it : indegree) {
            if (it.second == 0)
                q.push(it.first);
        }
        while (!q.empty()) {
            char node = q.front();
            q.pop();
            ans += node;
            for (char neighbor : graph[node]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0)
                    q.push(neighbor);
            }
        }
        // Step 4: If all nodes are included, return answer
        if (ans.size() == indegree.size())
            return ans;
        else
            return ""; // Cycle detected
    }
};

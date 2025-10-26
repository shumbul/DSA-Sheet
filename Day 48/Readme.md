# 🌐 Day 48: Graph Theory - Topological Sort & Advanced Algorithms

## 📚 Table of Contents
1. [Graph Representation](#graph-representation)
2. [Topological Sorting](#topological-sorting)
3. [Cycle Detection](#cycle-detection)
4. [Connected Components](#connected-components)
5. [Advanced Graph Algorithms](#advanced-graph-algorithms)
6. [Interview Strategy](#interview-strategy)

---

## 🏗️ Graph Representation

Understanding how to represent graphs efficiently is crucial for implementing algorithms correctly.

### **Adjacency List vs Adjacency Matrix**

```cpp
class GraphRepresentation {
public:
    // Adjacency List - Space: O(V + E)
    vector<vector<int>> adjList;
    
    // Adjacency Matrix - Space: O(V²)
    vector<vector<int>> adjMatrix;
    
    // For weighted graphs
    vector<vector<pair<int, int>>> weightedAdjList;  // {destination, weight}
    
    GraphRepresentation(int vertices) {
        adjList.resize(vertices);
        adjMatrix.resize(vertices, vector<int>(vertices, 0));
        weightedAdjList.resize(vertices);
    }
    
    // Add edge for undirected graph
    void addUndirectedEdge(int u, int v, int weight = 1) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
        
        adjMatrix[u][v] = weight;
        adjMatrix[v][u] = weight;
        
        weightedAdjList[u].push_back({v, weight});
        weightedAdjList[v].push_back({u, weight});
    }
    
    // Add edge for directed graph
    void addDirectedEdge(int u, int v, int weight = 1) {
        adjList[u].push_back(v);
        adjMatrix[u][v] = weight;
        weightedAdjList[u].push_back({v, weight});
    }
};
```

**When to use which:**
- **Adjacency List**: Dense graphs, need to iterate over neighbors
- **Adjacency Matrix**: Need to quickly check if edge exists, dense graphs

---

## 📊 Topological Sorting

**Topological sorting** is a linear ordering of vertices in a directed acyclic graph (DAG) such that for every directed edge (u, v), vertex u comes before v in the ordering.

### **Applications:**
- Course scheduling (prerequisite dependencies)
- Task scheduling
- Build systems (dependency resolution)
- Compiler optimization

### **Algorithm 1: Kahn's Algorithm (BFS-based)**
```cpp
class TopologicalSort {
public:
    // Kahn's Algorithm using BFS
    vector<int> topologicalSortBFS(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses, 0);
        
        // Build graph and calculate indegrees
        for (auto& prereq : prerequisites) {
            int course = prereq[0];
            int prerequisite = prereq[1];
            graph[prerequisite].push_back(course);
            indegree[course]++;
        }
        
        // Find all vertices with 0 indegree
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        
        vector<int> topologicalOrder;
        
        while (!q.empty()) {
            int current = q.front();
            q.pop();
            topologicalOrder.push_back(current);
            
            // Reduce indegree of neighbors
            for (int neighbor : graph[current]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        
        // Check if topological sort is possible (no cycles)
        return topologicalOrder.size() == numCourses ? topologicalOrder : vector<int>();
    }
    
    // Course Schedule I - Can finish all courses?
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> result = topologicalSortBFS(numCourses, prerequisites);
        return result.size() == numCourses;
    }
    
    // Course Schedule II - Return the order
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        return topologicalSortBFS(numCourses, prerequisites);
    }
};
```

### **Algorithm 2: DFS-based Topological Sort**
```cpp
class TopologicalSortDFS {
private:
    vector<vector<int>> graph;
    vector<int> color;  // 0: white, 1: gray, 2: black
    vector<int> result;
    bool hasCycle;
    
public:
    vector<int> topologicalSort(int n, vector<vector<int>>& edges) {
        graph.resize(n);
        color.resize(n, 0);
        hasCycle = false;
        
        // Build graph
        for (auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
        }
        
        // Run DFS from all unvisited vertices
        for (int i = 0; i < n; i++) {
            if (color[i] == 0) {
                dfs(i);
            }
        }
        
        if (hasCycle) return {};
        
        reverse(result.begin(), result.end());
        return result;
    }
    
private:
    void dfs(int node) {
        if (hasCycle) return;
        
        color[node] = 1;  // Mark as visiting (gray)
        
        for (int neighbor : graph[node]) {
            if (color[neighbor] == 1) {
                // Back edge found - cycle detected
                hasCycle = true;
                return;
            }
            
            if (color[neighbor] == 0) {
                dfs(neighbor);
            }
        }
        
        color[node] = 2;  // Mark as visited (black)
        result.push_back(node);  // Add to result in reverse order
    }
};
```

---

## 🔄 Cycle Detection

Detecting cycles is crucial for validating DAGs and ensuring topological sort is possible.

### **Cycle Detection in Directed Graph**
```cpp
class CycleDetection {
public:
    // Using DFS with colors
    bool hasCycleDFS(int n, vector<vector<int>>& graph) {
        vector<int> color(n, 0);  // 0: white, 1: gray, 2: black
        
        for (int i = 0; i < n; i++) {
            if (color[i] == 0 && dfsCycle(i, graph, color)) {
                return true;
            }
        }
        
        return false;
    }
    
private:
    bool dfsCycle(int node, vector<vector<int>>& graph, vector<int>& color) {
        color[node] = 1;  // Mark as visiting
        
        for (int neighbor : graph[node]) {
            if (color[neighbor] == 1) {
                return true;  // Back edge - cycle found
            }
            
            if (color[neighbor] == 0 && dfsCycle(neighbor, graph, color)) {
                return true;
            }
        }
        
        color[node] = 2;  // Mark as completed
        return false;
    }
    
public:
    // Using Kahn's algorithm approach
    bool hasCycleKahn(int n, vector<vector<int>>& graph) {
        vector<int> indegree(n, 0);
        
        // Calculate indegrees
        for (int i = 0; i < n; i++) {
            for (int neighbor : graph[i]) {
                indegree[neighbor]++;
            }
        }
        
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        
        int processedNodes = 0;
        
        while (!q.empty()) {
            int current = q.front();
            q.pop();
            processedNodes++;
            
            for (int neighbor : graph[current]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        
        // If we couldn't process all nodes, there's a cycle
        return processedNodes != n;
    }
};
```

### **Cycle Detection in Undirected Graph**
```cpp
class UndirectedCycleDetection {
public:
    bool hasCycle(int n, vector<vector<int>>& graph) {
        vector<bool> visited(n, false);
        
        for (int i = 0; i < n; i++) {
            if (!visited[i] && dfs(i, -1, graph, visited)) {
                return true;
            }
        }
        
        return false;
    }
    
private:
    bool dfs(int node, int parent, vector<vector<int>>& graph, vector<bool>& visited) {
        visited[node] = true;
        
        for (int neighbor : graph[node]) {
            if (neighbor == parent) continue;  // Skip parent
            
            if (visited[neighbor] || dfs(neighbor, node, graph, visited)) {
                return true;
            }
        }
        
        return false;
    }
};
```

---

## 🔗 Connected Components

Finding connected components helps understand the structure of graphs.

### **Connected Components in Undirected Graph**
```cpp
class ConnectedComponents {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        
        // Build adjacency list
        for (auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        vector<bool> visited(n, false);
        int components = 0;
        
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(i, graph, visited);
                components++;
            }
        }
        
        return components;
    }
    
    // Get all components with their nodes
    vector<vector<int>> getAllComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        
        for (auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        vector<bool> visited(n, false);
        vector<vector<int>> components;
        
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                vector<int> component;
                dfsCollect(i, graph, visited, component);
                components.push_back(component);
            }
        }
        
        return components;
    }
    
private:
    void dfs(int node, vector<vector<int>>& graph, vector<bool>& visited) {
        visited[node] = true;
        
        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, graph, visited);
            }
        }
    }
    
    void dfsCollect(int node, vector<vector<int>>& graph, vector<bool>& visited, vector<int>& component) {
        visited[node] = true;
        component.push_back(node);
        
        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                dfsCollect(neighbor, graph, visited, component);
            }
        }
    }
};
```

### **Strongly Connected Components (Kosaraju's Algorithm)**
```cpp
class StronglyConnectedComponents {
public:
    vector<vector<int>> kosaraju(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n), reverseGraph(n);
        
        // Build original and reverse graphs
        for (auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            reverseGraph[edge[1]].push_back(edge[0]);
        }
        
        // Step 1: Get finishing order using DFS on original graph
        vector<bool> visited(n, false);
        stack<int> finishStack;
        
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs1(i, graph, visited, finishStack);
            }
        }
        
        // Step 2: DFS on reverse graph in reverse finishing order
        fill(visited.begin(), visited.end(), false);
        vector<vector<int>> sccs;
        
        while (!finishStack.empty()) {
            int node = finishStack.top();
            finishStack.pop();
            
            if (!visited[node]) {
                vector<int> scc;
                dfs2(node, reverseGraph, visited, scc);
                sccs.push_back(scc);
            }
        }
        
        return sccs;
    }
    
private:
    void dfs1(int node, vector<vector<int>>& graph, vector<bool>& visited, stack<int>& finishStack) {
        visited[node] = true;
        
        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                dfs1(neighbor, graph, visited, finishStack);
            }
        }
        
        finishStack.push(node);  // Add to stack when finished
    }
    
    void dfs2(int node, vector<vector<int>>& reverseGraph, vector<bool>& visited, vector<int>& scc) {
        visited[node] = true;
        scc.push_back(node);
        
        for (int neighbor : reverseGraph[node]) {
            if (!visited[neighbor]) {
                dfs2(neighbor, reverseGraph, visited, scc);
            }
        }
    }
};
```

---

## 🚀 Advanced Graph Algorithms

### **Union-Find (Disjoint Set Union)**
```cpp
class UnionFind {
private:
    vector<int> parent, rank;
    int components;
    
public:
    UnionFind(int n) : components(n) {
        parent.resize(n);
        rank.resize(n, 0);
        iota(parent.begin(), parent.end(), 0);  // parent[i] = i
    }
    
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);  // Path compression
        }
        return parent[x];
    }
    
    bool unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        
        if (rootX == rootY) return false;  // Already connected
        
        // Union by rank
        if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
        
        components--;
        return true;
    }
    
    bool connected(int x, int y) {
        return find(x) == find(y);
    }
    
    int getComponents() {
        return components;
    }
};

// Application: Number of Islands
class NumberOfIslands {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;
        
        int m = grid.size(), n = grid[0].size();
        UnionFind uf(m * n);
        int waterCells = 0;
        
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '0') {
                    waterCells++;
                    continue;
                }
                
                int currentId = i * n + j;
                
                // Check all 4 directions
                for (auto [di, dj] : directions) {
                    int ni = i + di, nj = j + dj;
                    
                    if (ni >= 0 && ni < m && nj >= 0 && nj < n && grid[ni][nj] == '1') {
                        int neighborId = ni * n + nj;
                        uf.unite(currentId, neighborId);
                    }
                }
            }
        }
        
        return uf.getComponents() - waterCells;
    }
};
```

### **Minimum Spanning Tree (Kruskal's Algorithm)**
```cpp
class MinimumSpanningTree {
public:
    struct Edge {
        int u, v, weight;
        bool operator<(const Edge& other) const {
            return weight < other.weight;
        }
    };
    
    vector<Edge> kruskalMST(int n, vector<Edge>& edges) {
        sort(edges.begin(), edges.end());  // Sort by weight
        
        UnionFind uf(n);
        vector<Edge> mst;
        int totalWeight = 0;
        
        for (const Edge& edge : edges) {
            if (uf.unite(edge.u, edge.v)) {
                mst.push_back(edge);
                totalWeight += edge.weight;
                
                if (mst.size() == n - 1) break;  // MST complete
            }
        }
        
        return mst;
    }
    
    // Find MST weight
    int findMSTWeight(int n, vector<vector<int>>& connections) {
        vector<Edge> edges;
        
        for (auto& conn : connections) {
            edges.push_back({conn[0], conn[1], conn[2]});
        }
        
        vector<Edge> mst = kruskalMST(n, edges);
        
        if (mst.size() != n - 1) return -1;  // No spanning tree possible
        
        int totalWeight = 0;
        for (const Edge& edge : mst) {
            totalWeight += edge.weight;
        }
        
        return totalWeight;
    }
};
```

---

## 🎯 Interview Strategy

### **Problem Recognition Patterns:**

#### **Topological Sort Problems:**
- "Course prerequisites"
- "Task dependencies"
- "Build order"
- "Alien dictionary"

#### **Cycle Detection Problems:**
- "Can finish all courses?"
- "Circular dependencies"
- "Deadlock detection"

#### **Connected Components:**
- "Number of islands"
- "Friend circles"
- "Network connectivity"

### **Algorithm Selection Guide:**

| Problem Type | Algorithm | Time | Space | When to Use |
|--------------|-----------|------|-------|-------------|
| **Topological Sort** | Kahn's (BFS) | O(V+E) | O(V) | Need lexicographic order |
| **Topological Sort** | DFS-based | O(V+E) | O(V) | Detect cycles simultaneously |
| **Cycle Detection** | DFS Colors | O(V+E) | O(V) | Directed graphs |
| **Cycle Detection** | Union-Find | O(E⋅α(V)) | O(V) | Undirected graphs |
| **Connected Components** | DFS/BFS | O(V+E) | O(V) | Simple connectivity |
| **Connected Components** | Union-Find | O(E⋅α(V)) | O(V) | Dynamic connectivity |

### **Implementation Templates:**

#### **Template 1: Basic Graph Traversal**
```cpp
void dfs(int node, vector<vector<int>>& graph, vector<bool>& visited) {
    visited[node] = true;
    // Process current node
    
    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, graph, visited);
        }
    }
}
```

#### **Template 2: Topological Sort (Kahn's)**
```cpp
vector<int> topologicalSort(int n, vector<vector<int>>& graph) {
    vector<int> indegree(n, 0);
    
    // Calculate indegrees
    for (int i = 0; i < n; i++) {
        for (int neighbor : graph[i]) {
            indegree[neighbor]++;
        }
    }
    
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) q.push(i);
    }
    
    vector<int> result;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        result.push_back(node);
        
        for (int neighbor : graph[node]) {
            indegree[neighbor]--;
            if (indegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }
    
    return result.size() == n ? result : vector<int>();
}
```

---

## 🏆 Common Interview Problems

### **1. Course Schedule Series**
- Course Schedule I & II
- Parallel Courses
- Course Schedule III

### **2. Alien Dictionary**
- Build character ordering from sorted alien words
- Use topological sort on character dependencies

### **3. Minimum Height Trees**
- Find roots that minimize tree height
- Use topological sort by removing leaves

### **4. Graph Valid Tree**
- Check if graph forms valid tree
- Must be connected and acyclic

---

## 🎮 Practice Progression

### **Level 1: Fundamentals**
1. Course Schedule (I & II)
2. Number of Islands
3. Clone Graph

### **Level 2: Intermediate**
4. Alien Dictionary
5. Minimum Height Trees
6. Graph Valid Tree

### **Level 3: Advanced**
7. Critical Connections in Network
8. Strongly Connected Components
9. Minimum Spanning Tree

---

*Master these graph algorithms and you'll be prepared for any graph theory challenge in interviews! 🌐*
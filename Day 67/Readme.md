# 🛣️ Day 67: Shortest Path Algorithms - Complete Guide

## 📚 Table of Contents
1. [Algorithm Overview](#algorithm-overview)
2. [Dijkstra's Algorithm](#dijkstras-algorithm)
3. [Bellman-Ford Algorithm](#bellman-ford-algorithm)
4. [Algorithm Comparison](#algorithm-comparison)
5. [Implementation Patterns](#implementation-patterns)
6. [Interview Strategy](#interview-strategy)

---

## 🎯 Algorithm Overview

Shortest path algorithms find the minimum cost path between vertices in a weighted graph. The choice of algorithm depends on graph properties:

| Algorithm | Graph Type | Negative Weights | Time Complexity | Space | Use Case |
|-----------|------------|------------------|-----------------|-------|----------|
| **Dijkstra** | Directed/Undirected | ❌ No | O((V+E)logV) | O(V) | GPS Navigation |
| **Bellman-Ford** | Directed/Undirected | ✅ Yes | O(VE) | O(V) | Currency Exchange |
| **Floyd-Warshall** | Directed/Undirected | ✅ Yes | O(V³) | O(V²) | All-pairs shortest |
| **BFS** | Unweighted | N/A | O(V+E) | O(V) | Simple paths |

---

## 🚀 Dijkstra's Algorithm

### **Core Concept:**
Greedy algorithm that explores vertices in order of increasing distance from source. Uses priority queue to always process the closest unvisited vertex.

### **Key Properties:**
- ✅ **Works with**: Non-negative edge weights
- ❌ **Fails with**: Negative edge weights
- 🎯 **Optimal for**: Single-source shortest path with non-negative weights
- ⚡ **Time**: O((V+E)logV) with binary heap

### **Complete Implementation:**
```cpp
class DijkstraGraph {
private:
    int vertices;
    vector<vector<pair<int, int>>> adjList;  // {destination, weight}
    
public:
    DijkstraGraph(int V) : vertices(V) {
        adjList.resize(V);
    }
    
    void addEdge(int u, int v, int weight) {
        adjList[u].push_back({v, weight});
        // For undirected graph, add reverse edge:
        // adjList[v].push_back({u, weight});
    }
    
    vector<int> dijkstra(int source) {
        // Distance array initialized to infinity
        vector<int> dist(vertices, INT_MAX);
        
        // Min-heap: {distance, vertex}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        // Distance to source is 0
        dist[source] = 0;
        pq.push({0, source});
        
        while (!pq.empty()) {
            int currentDist = pq.top().first;
            int u = pq.top().second;
            pq.pop();
            
            // Skip if we've already found a better path
            if (currentDist > dist[u]) continue;
            
            // Check all neighbors
            for (auto& edge : adjList[u]) {
                int v = edge.first;
                int weight = edge.second;
                
                // Relaxation step
                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }
        
        return dist;
    }
    
    // Get shortest path (not just distance)
    vector<int> getShortestPath(int source, int target) {
        vector<int> dist(vertices, INT_MAX);
        vector<int> parent(vertices, -1);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        dist[source] = 0;
        pq.push({0, source});
        
        while (!pq.empty()) {
            int currentDist = pq.top().first;
            int u = pq.top().second;
            pq.pop();
            
            if (currentDist > dist[u]) continue;
            
            for (auto& edge : adjList[u]) {
                int v = edge.first;
                int weight = edge.second;
                
                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    parent[v] = u;
                    pq.push({dist[v], v});
                }
            }
        }
        
        // Reconstruct path
        vector<int> path;
        int current = target;
        
        while (current != -1) {
            path.push_back(current);
            current = parent[current];
        }
        
        reverse(path.begin(), path.end());
        
        // Return empty path if target is unreachable
        return (dist[target] == INT_MAX) ? vector<int>() : path;
    }
};
```

### **Dijkstra Variations:**

#### **1. Early Termination (Single Target)**
```cpp
int dijkstraToTarget(int source, int target) {
    vector<int> dist(vertices, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    dist[source] = 0;
    pq.push({0, source});
    
    while (!pq.empty()) {
        int currentDist = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        
        // Early termination when target is reached
        if (u == target) {
            return dist[target];
        }
        
        if (currentDist > dist[u]) continue;
        
        for (auto& edge : adjList[u]) {
            int v = edge.first;
            int weight = edge.second;
            
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
    
    return -1;  // Target unreachable
}
```

#### **2. K Shortest Paths**
```cpp
vector<vector<int>> kShortestPaths(int source, int target, int k) {
    vector<vector<int>> result;
    priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, greater<pair<int, vector<int>>>> pq;
    
    pq.push({0, {source}});
    
    while (!pq.empty() && result.size() < k) {
        auto current = pq.top();
        pq.pop();
        
        int dist = current.first;
        vector<int> path = current.second;
        int lastVertex = path.back();
        
        if (lastVertex == target) {
            result.push_back(path);
            continue;
        }
        
        for (auto& edge : adjList[lastVertex]) {
            int nextVertex = edge.first;
            int weight = edge.second;
            
            vector<int> newPath = path;
            newPath.push_back(nextVertex);
            
            pq.push({dist + weight, newPath});
        }
    }
    
    return result;
}
```

---

## ⚡ Bellman-Ford Algorithm

### **Core Concept:**
Dynamic programming approach that relaxes all edges V-1 times. Can detect negative cycles and handle negative edge weights.

### **Key Properties:**
- ✅ **Works with**: Negative edge weights
- ✅ **Detects**: Negative cycles
- 🎯 **Optimal for**: Graphs with negative weights, cycle detection
- ⏱️ **Time**: O(VE) - slower than Dijkstra

### **Complete Implementation:**
```cpp
class BellmanFordGraph {
private:
    struct Edge {
        int from, to, weight;
        Edge(int f, int t, int w) : from(f), to(t), weight(w) {}
    };
    
    int vertices;
    vector<Edge> edges;
    
public:
    BellmanFordGraph(int V) : vertices(V) {}
    
    void addEdge(int u, int v, int weight) {
        edges.push_back(Edge(u, v, weight));
    }
    
    pair<vector<int>, bool> bellmanFord(int source) {
        vector<int> dist(vertices, INT_MAX);
        dist[source] = 0;
        
        // Relax all edges V-1 times
        for (int i = 0; i < vertices - 1; i++) {
            bool updated = false;
            
            for (const Edge& edge : edges) {
                if (dist[edge.from] != INT_MAX && 
                    dist[edge.from] + edge.weight < dist[edge.to]) {
                    dist[edge.to] = dist[edge.from] + edge.weight;
                    updated = true;
                }
            }
            
            // Early termination if no updates
            if (!updated) break;
        }
        
        // Check for negative cycles
        bool hasNegativeCycle = false;
        for (const Edge& edge : edges) {
            if (dist[edge.from] != INT_MAX && 
                dist[edge.from] + edge.weight < dist[edge.to]) {
                hasNegativeCycle = true;
                break;
            }
        }
        
        return {dist, hasNegativeCycle};
    }
    
    // Find vertices affected by negative cycles
    vector<bool> findNegativeCycleVertices(int source) {
        vector<int> dist(vertices, INT_MAX);
        vector<bool> inNegativeCycle(vertices, false);
        dist[source] = 0;
        
        // Standard Bellman-Ford relaxation
        for (int i = 0; i < vertices - 1; i++) {
            for (const Edge& edge : edges) {
                if (dist[edge.from] != INT_MAX && 
                    dist[edge.from] + edge.weight < dist[edge.to]) {
                    dist[edge.to] = dist[edge.from] + edge.weight;
                }
            }
        }
        
        // Mark vertices that can still be relaxed (part of negative cycle)
        for (int i = 0; i < vertices; i++) {
            for (const Edge& edge : edges) {
                if (dist[edge.from] != INT_MAX && 
                    dist[edge.from] + edge.weight < dist[edge.to]) {
                    dist[edge.to] = dist[edge.from] + edge.weight;
                    inNegativeCycle[edge.to] = true;
                }
                
                // Propagate negative cycle marking
                if (inNegativeCycle[edge.from]) {
                    inNegativeCycle[edge.to] = true;
                }
            }
        }
        
        return inNegativeCycle;
    }
};
```

### **SPFA (Shortest Path Faster Algorithm)**
Optimized version of Bellman-Ford using queue:

```cpp
vector<int> spfa(int source) {
    vector<int> dist(vertices, INT_MAX);
    vector<bool> inQueue(vertices, false);
    queue<int> q;
    
    dist[source] = 0;
    q.push(source);
    inQueue[source] = true;
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        inQueue[u] = false;
        
        for (auto& edge : adjList[u]) {
            int v = edge.first;
            int weight = edge.second;
            
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                
                if (!inQueue[v]) {
                    q.push(v);
                    inQueue[v] = true;
                }
            }
        }
    }
    
    return dist;
}
```

---

## 📊 Algorithm Comparison

### **Performance Analysis:**

| Aspect | Dijkstra | Bellman-Ford | Floyd-Warshall |
|--------|----------|--------------|----------------|
| **Time** | O((V+E)logV) | O(VE) | O(V³) |
| **Space** | O(V + E) | O(V + E) | O(V²) |
| **Negative Weights** | ❌ | ✅ | ✅ |
| **Negative Cycles** | ❌ | ✅ Detect | ✅ Detect |
| **Single Source** | ✅ Optimal | ✅ Works | ✅ Overkill |
| **All Pairs** | O(V·(V+E)logV) | O(V²E) | ✅ Optimal |
| **Sparse Graphs** | ✅ Excellent | ✅ Good | ❌ Poor |
| **Dense Graphs** | ✅ Good | ❌ Poor | ✅ Acceptable |

### **When to Use Which:**

#### **Use Dijkstra When:**
- ✅ All edge weights are non-negative
- ✅ Need optimal performance for single-source
- ✅ Graph is sparse (E << V²)
- ✅ Real-time applications (GPS, network routing)

#### **Use Bellman-Ford When:**
- ✅ Graph has negative edge weights
- ✅ Need to detect negative cycles
- ✅ Graph is small to medium sized
- ✅ Currency arbitrage, network delay analysis

#### **Use Floyd-Warshall When:**
- ✅ Need all-pairs shortest paths
- ✅ Graph is dense (E ≈ V²)
- ✅ Graph is small (V ≤ 400)
- ✅ Distance matrix applications

---

## 🎯 Implementation Patterns

### **Pattern 1: Priority Queue Dijkstra**
```cpp
template<typename T>
vector<T> dijkstraTemplate(int source, const vector<vector<pair<int, T>>>& graph) {
    int n = graph.size();
    vector<T> dist(n, numeric_limits<T>::max());
    priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>> pq;
    
    dist[source] = 0;
    pq.push({0, source});
    
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        
        if (d > dist[u]) continue;
        
        for (auto [v, w] : graph[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    
    return dist;
}
```

### **Pattern 2: Edge List Bellman-Ford**
```cpp
template<typename T>
pair<vector<T>, bool> bellmanFordTemplate(int source, int vertices, 
                                         const vector<tuple<int, int, T>>& edges) {
    vector<T> dist(vertices, numeric_limits<T>::max());
    dist[source] = 0;
    
    // Relax edges V-1 times
    for (int i = 0; i < vertices - 1; i++) {
        for (auto [u, v, w] : edges) {
            if (dist[u] != numeric_limits<T>::max() && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }
    
    // Check for negative cycles
    bool hasNegativeCycle = false;
    for (auto [u, v, w] : edges) {
        if (dist[u] != numeric_limits<T>::max() && dist[u] + w < dist[v]) {
            hasNegativeCycle = true;
            break;
        }
    }
    
    return {dist, hasNegativeCycle};
}
```

---

## 🎯 Interview Strategy

### **Problem Recognition:**
Look for these keywords:
- "Shortest path"
- "Minimum cost"
- "Cheapest route"
- "Currency exchange" (negative weights)
- "Network delay"

### **Decision Tree:**
```
Graph has negative weights?
├─ Yes → Can have negative cycles?
│  ├─ Yes → Use Bellman-Ford
│  └─ No → Use Dijkstra (if cycles impossible) or Bellman-Ford
└─ No → Single source?
   ├─ Yes → Use Dijkstra
   └─ No → All pairs?
      ├─ Small graph → Floyd-Warshall
      └─ Large graph → Multiple Dijkstra calls
```

### **Common Interview Variations:**
1. **"Find shortest path in maze"** → BFS (unweighted) or Dijkstra (weighted)
2. **"Network delay time"** → Dijkstra from source node
3. **"Cheapest flights with K stops"** → Modified Dijkstra with state
4. **"Currency arbitrage"** → Bellman-Ford for negative cycle detection
5. **"Path with minimum effort"** → Binary search + BFS or Dijkstra

### **Implementation Checklist:**
```cpp
// 1. Choose correct data structure
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // Min-heap

// 2. Initialize distances correctly
vector<int> dist(n, INT_MAX);
dist[source] = 0;

// 3. Handle unreachable vertices
if (dist[target] == INT_MAX) return -1;

// 4. Check for negative cycles (Bellman-Ford)
for (auto [u, v, w] : edges) {
    if (dist[u] + w < dist[v]) {
        // Negative cycle detected
    }
}

// 5. Reconstruct path if needed
vector<int> parent(n, -1);
// Update parent during relaxation
parent[v] = u;
```

### **Time/Space Complexity Cheat Sheet:**
- **Dijkstra**: Always mention O((V+E)logV) with binary heap
- **Bellman-Ford**: O(VE) time, can optimize to O(V+E) average with SPFA
- **Space**: Both use O(V) space for distance array

---

## 🏆 Advanced Applications

### **1. A* Search Algorithm**
```cpp
// Dijkstra with heuristic for pathfinding
int astar(int source, int target, function<int(int)> heuristic) {
    priority_queue<pair<int, pair<int, int>>, 
                   vector<pair<int, pair<int, int>>>, 
                   greater<pair<int, pair<int, int>>>> pq;
    
    // {f_score, {g_score, vertex}}
    pq.push({heuristic(source), {0, source}});
    
    vector<int> g_score(vertices, INT_MAX);
    g_score[source] = 0;
    
    while (!pq.empty()) {
        auto current = pq.top();
        pq.pop();
        
        int g = current.second.first;
        int u = current.second.second;
        
        if (u == target) return g;
        
        if (g > g_score[u]) continue;
        
        for (auto [v, w] : adjList[u]) {
            int tentative_g = g_score[u] + w;
            
            if (tentative_g < g_score[v]) {
                g_score[v] = tentative_g;
                int f_score = tentative_g + heuristic(v);
                pq.push({f_score, {tentative_g, v}});
            }
        }
    }
    
    return -1;
}
```

### **2. Johnson's Algorithm (All-Pairs with Negative Weights)**
Combines Bellman-Ford and Dijkstra for optimal all-pairs shortest paths.

---

*Master these algorithms and you'll be prepared for any shortest path challenge! 🚀*
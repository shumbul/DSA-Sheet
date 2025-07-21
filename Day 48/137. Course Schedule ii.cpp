//BFS
class Solution {
        set<int> visited_dp;
    set<int> currVisited;
    unordered_map<int, vector<int>> graph;
    vector<int> order;
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
         for (int i = 0; i < prerequisites.size(); i++) {
            graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        // 2. check if each course can be completed
        for (int i = 0; i < numCourses; i++) {
            if (visited_dp.find(i)!=visited_dp.end())
                continue;
            if (hasCycle(i))
                return {};
        }
        return order;
    }
    bool hasCycle(int node) {
        // 3. Check if node is already visited. If yes, return true for cycle, else simply insert node
        if (currVisited.find(node) != currVisited.end())
            return true;
        if (visited_dp.find(node)!=visited_dp.end())
            return false;
        currVisited.insert(node);
        // 4. do the same for neighbours
        for (auto i : graph[node]) {
            if (hasCycle(i))
                return true;
        }
        //5. erase it from currVisited as we will be checking all nodes one by one in main function
        currVisited.erase(node);
        visited_dp.insert(node); //marking node as safe
        order.push_back(node);
        return false;
    }
};

//DFS
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> graph;
        vector<int> indegree(numCourses, 0);
        vector<int> order; // This will store the topological order
        // Step 1: Build graph and indegree array
        for (auto i : prerequisites) {
            graph[i[1]].push_back(i[0]);  // i[1] -> i[0]
            indegree[i[0]]++;
        }
        // Step 2: Add all courses with 0 indegree to queue
        queue<int> courses;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0)
                courses.push(i);
        }
        // Step 3: Process queue (Topological Sort)
        while (!courses.empty()) {
            int frontt = courses.front();
            courses.pop();
            order.push_back(frontt); // Record this course
            for (int nbr : graph[frontt]) {
                indegree[nbr]--;
                if (indegree[nbr] == 0)
                    courses.push(nbr);
            }
        }
        // Step 4: Check if topological ordering includes all courses
        if (order.size() == numCourses)
            return order;
        else
            return {}; // Cycle detected, no valid ordering
    }
};

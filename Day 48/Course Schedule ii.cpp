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

//DFS
class Solution {
    set<int> visited_dp;
    set<int> currVisited;
    unordered_map<int, vector<int>> graph;

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // 1. form a graph
        for (int i = 0; i < prerequisites.size(); i++) {
            graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        // 2. check if each course can be completed
        for (int i = 0; i < numCourses; i++) {
            if (visited_dp.find(i)!=visited_dp.end())
                continue;
            if (hasCycle(i))
                return false;
        }
        return true;
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
        return false;
    }
};

//BFS
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> graph;
        vector<int> indegree(numCourses, 0);
        int ans=0;
        queue<int> courses;
        for (auto i:prerequisites)
        {
            graph[i[1]].push_back(i[0]);
            indegree[i[0]]++;
        }
        for (int i=0;i<indegree.size();i++)
        {
            if (indegree[i]==0)
                courses.push(i);
        }
        while (!courses.empty())
        {
            int frontt=courses.front();
            courses.pop();
            ans++; //one more course successfully taken
            for (int nbr:graph[frontt])
            {
                indegree[nbr]--;
                if (indegree[nbr]==0)
                    courses.push(nbr);
            }
        }
        if (ans==numCourses) //If we successfully processed all numCourses, there is no cycle, and all courses can be completed
            return true;
        return false;
    }
};

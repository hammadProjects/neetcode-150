class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        queue<int> q;
        vector<int> topo_sort;
        for(auto& prereq: prerequisites) {
            adj[prereq[1]].push_back(prereq[0]);
            indegree[prereq[0]]++;
        }

        for(int i = 0; i < numCourses; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }

        while(!q.empty()) {
            int course = q.front();
            q.pop();

            for(int ngbr: adj[course]) {
                indegree[ngbr]--;
                if(indegree[ngbr] == 0) {
                    q.push(ngbr);
                }
            }

            topo_sort.push_back(course);
        }

        if(topo_sort.size() == numCourses) {
            return topo_sort;
        }

        return {};
    }
};
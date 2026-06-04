class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj(numCourses);
        vector<bool> vis(numCourses, false);
        for(auto& prereq: prerequisites) {
            adj[prereq[0]].push_back(prereq[1]);
        }


        for(int course = 0; course < numCourses; course++) {
            if(!dfs(adj, vis, course)) {
                return false;
            }
        }

        return true;
    }

private:
    bool dfs(unordered_map<int, vector<int>>& adj, vector<bool>& vis, int idx) {
        if(vis[idx]) return false;
        vis[idx] = true;

        for(int ngbr : adj[idx]) {
            if(!dfs(adj, vis, ngbr)) {
                return false;
            }
        }

        vis[idx] = false;
        return true;
    }
};
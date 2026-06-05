class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> vis(n, 0);
        for(auto& edge: edges) {
            if(edge[0] == edge[1]) return false;
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        if(!dfs(0, 0, adj, vis))
            return false;

        for(int node = 0; node < n; node++)
            if(!vis[node])
                return false;

        return true;
    }

private:
    bool dfs(int node, int parent, vector<vector<int>>& adj, vector<int>& vis) {
        vis[node] = 1;

        for(int ngbr: adj[node]) {
            if(ngbr == parent)
                continue;

            if(vis[ngbr]) return false;

            if(!dfs(ngbr, node, adj, vis))
                return false;
        }

        return true;
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> adj(n + 1);
        vector<int> vis(n + 1, 0);

        for(auto& edge: edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);

            if(!dfs(u, -1, adj, vis))
                return {u, v};
        }

        return {};
    }

private:
    bool dfs(int node, int parent, vector<vector<int>>& adj, vector<int>& vis) {
        vis[node] = 1;

        for(int ngbr: adj[node]) {
            if(ngbr == parent)
                continue;

            if(vis[ngbr] || !dfs(ngbr, node, adj, vis))
                return false;
        }

        vis[node] = 0;
        return true;
    }
};
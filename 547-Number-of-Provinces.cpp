class Solution {
public:
    void dfs(int node, vector<vector<int>> &adjLs, vector<bool> &vis) {
        vis[node] = 1; 
        for(auto it: adjLs[node]) {
            if(!vis[it]) {
                dfs(it, adjLs, vis); 
            }
        }
    }

    int findCircleNum(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<vector<int>> adjLs(n); 
        for(int i = 0;i<adj.size();i++) {
            for(int j = 0;j<adj.size();j++) {
                if(adj[i][j] == 1 && i != j) {
                    adjLs[i].push_back(j); 
                    adjLs[j].push_back(i); 
                }
            }
        }
        vector<bool> vis(n,false); 
        int cnt = 0; 
        for(int i = 0;i<n;i++) {
            if(!vis[i]) {
                cnt++;
               dfs(i, adjLs, vis); 
            }
        }
        return cnt; 
    }
};
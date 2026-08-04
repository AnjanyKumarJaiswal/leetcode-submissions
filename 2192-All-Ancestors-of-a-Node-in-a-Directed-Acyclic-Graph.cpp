class Solution {
public:
    void dfs(int node, vector<vector<int>> &adj , vector<bool> &visited,vector<int> &temp){
        visited[node] = true;
        for(int &v : adj[node]){
            if(!visited[v]){
                temp.push_back(v);
                dfs(v,adj,visited,temp);
            }
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto &edge : edges){
            adj[edge[1]].push_back(edge[0]);
        }
        vector<bool> visited(n,false);
        vector<vector<int>> ans;
        for(int i = 0; i<n; i++){
            vector<int> temp;
            fill(visited.begin(),visited.end(),false);
            dfs(i,adj,visited,temp);
            sort(temp.begin(),temp.end());
            ans.push_back(temp);
        }
        return ans;
    }
};
class Solution {
public:
    void dfs(unordered_map<int,vector<int>>& graph, vector<int>& component , int curr_node , int compId){
        component[curr_node] = compId;
        for(int& neighbour : graph[curr_node]){
            if(component[neighbour] == -1){
                dfs(graph,component,neighbour,compId);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        int res = 0;
        unordered_map<int,vector<int>> graph(n);
        for(auto &edge : edges){
            int a = edge[0];
            int b = edge[1];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        vector<int> component(n,-1);
        int compId=0;
        for(int i = 0; i<n; i++){
            if(component[i] == -1){
                dfs(graph,component,i,compId);
                compId++;
            }
        }
        unordered_map<int,int> node_count;
        unordered_map<int,int> total_degree;
        for(int i = 0; i<n; i++){
            node_count[component[i]]++;
            total_degree[component[i]]+=graph[i].size();
        }
        for(int i = 0; i<compId; i++){
            int actual_edges = total_degree[i]/2;
            if(actual_edges == (node_count[i]*(node_count[i]-1)/2)){
                res++;
            }
        }
        return res;
    }
};
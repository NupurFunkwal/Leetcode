class Solution {
public:
    void dfs(vector<vector<int>> &graph, vector<vector<int>> &ans, vector<int> &temp, int src, int dest, vector<bool> &visited){
        visited[src] = true;
        temp.emplace_back(src);
        if(src == dest){
            ans.emplace_back(temp);
        }
        else{
            for(int i=0; i<graph[src].size(); i++){
                if(visited[graph[src][i]] == false){
                    dfs(graph, ans, temp, graph[src][i], dest, visited);
                }
            }
        }
        
        temp.pop_back();
        visited[src] = false;
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> ans;
        vector<int> temp;
        vector<bool> visited(n);
        dfs(graph, ans, temp, 0, n-1, visited);
        return ans;
    }
};
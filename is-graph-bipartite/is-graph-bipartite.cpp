class Solution {
public:
    bool bfs(vector<vector<int>> &graph, vector<int> &visited, queue<int> &q){
        while(q.empty() == false){
            int i = q.front();
            q.pop();
            int color = visited[i];
            for(int x = 0; x<graph[i].size(); x++){
                if(visited[graph[i][x]] ==0){
                    visited[graph[i][x]] = color == 1? 2:1;
                    q.emplace(graph[i][x]);
                }
                else{
                    if( visited[graph[i][x]] == color){
                        return false;
                    }
                }
            }
        }
        return true;
        
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> visited(n,0);
        visited[0] = 1;
        queue<int> q;
        q.emplace(0);
        if(bfs(graph, visited,q) == false){
            return false;
        }
        
        for(int i=0; i<n;i++){
            if(visited[i] == 0){
                q.emplace(i);
                if(bfs(graph, visited, q) == false){
                    return false;
                }
            }
        }
        
        return true;
        
        
        
    }
};
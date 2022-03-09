class Solution {
public:
    int ans=0;
    
    void dfs(vector<vector<int>> &graph, vector<bool> &visited, int temp, int source, vector<int> &informTime){
        visited[source]=true;
        temp+= informTime[source];
        ans = max(ans, temp);
        
        for(int i=0; i<graph[source].size(); i++){
            if(!visited[graph[source][i]]){
                dfs(graph, visited, temp, graph[source][i], informTime);
            }
        }
    }
    
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> graph(n);
        int source;
        
        for(int i=0; i<n ;i++){
            if(manager[i]==-1){
                source=i;
                continue;
            }
            
            graph[i].emplace_back(manager[i]);
            graph[manager[i]].emplace_back(i); 
        }
        
        int temp=0;
        vector<bool> visited(n, false);
        dfs(graph, visited, temp, source, informTime);
        return ans;
    }
};
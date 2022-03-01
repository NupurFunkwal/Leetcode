// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool util(int index, vector<int>adj[], int V, vector<bool> &visited, vector<bool> &recstack){
        visited[index]=true;
        recstack[index]=true;
        for(int i=0; i<adj[index].size(); i++){
            if(!visited[adj[index][i]]){
                if(util(adj[index][i], adj, V, visited, recstack)){
                    return true;
                }
            }
            else{
                if(recstack[adj[index][i]]){
                    return true;
                }
            }
        }
        recstack[index]=false;
        return false;
    }
    
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<bool> recstack(V, false);
        vector<bool> visited(V, false);
        
        for(int i=0; i<V; i++){
            if(!visited[i]){
                if(util(i, adj, V, visited, recstack)){
                    return true;
                }
            }
        }
        return false;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends
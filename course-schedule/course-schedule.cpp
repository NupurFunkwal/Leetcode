class Solution {
public:
    bool cycle(vector<vector<int>> &adj, vector<bool> &visited, vector<bool> &recstack, int x){
        visited[x] = true;
        recstack[x] = true;
        
        vector<int> :: iterator it;
        for(it = adj[x].begin(); it!=adj[x].end(); it++){
            if(visited[*it] == false){
                if(cycle(adj, visited, recstack, *it) == true){
                    return true;
                }
            }
            else if(recstack[*it] == true){
                return true;
            }
        }
        recstack[x] = false;
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        int n = prerequisites.size();
        for(int i=0; i<n; i++){
            adj[prerequisites[i][0]].emplace_back(prerequisites[i][1]);
        }
        vector<bool> visited(numCourses, false);
        vector<bool> recstack(numCourses, false);
        
        for(int i=0; i<numCourses; i++){
            if(visited[i] == false){
                if(cycle(adj, visited, recstack, i)==true){
                    return false;
                }
            }
        }
        return true;
    }
};
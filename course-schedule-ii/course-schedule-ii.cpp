class Solution {
public:
    bool cycle(vector<vector<int>> &adj, vector<bool> &visited, vector<bool> &recstack, int x, stack<int> &s){
        visited[x] = true;
        recstack[x] = true;
        
        vector<int> :: iterator it;
        for(it = adj[x].begin(); it!=adj[x].end(); it++){
            if(visited[*it] == false){
                if(cycle(adj, visited, recstack, *it, s) == true){
                    return true;
                }
            }
            else if(recstack[*it] == true){
                return true;
            }
        }
        s.push(x);
        recstack[x] = false;
        return false;
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        stack<int> s;
        int n = prerequisites.size();
        vector<int> result;
        for(int i=0; i<n; i++){
            adj[prerequisites[i][1]].emplace_back(prerequisites[i][0]);
        }
        vector<bool> visited(numCourses, false);
        vector<bool> recstack(numCourses, false);
        
        for(int i=0; i<numCourses; i++){
            if(visited[i] == false){
                if(cycle(adj, visited, recstack, i, s)==true){
                    return result;
                }
            }
        }
        while(s.empty()==false){
            result.emplace_back(s.top());
            s.pop();
        }
        return result;
    }
};
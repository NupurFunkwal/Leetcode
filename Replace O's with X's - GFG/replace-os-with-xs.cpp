// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int move[4][2]= {{0,1}, {0,-1}, {1,0}, {-1,0}};
    
    void bfs(int x, int y, vector<vector<char>> &mat){
        //base case
        int n=mat.size();
        int m=mat[0].size();
        
        if(mat[x][y]=='X'){
            return;
        }
        
        mat[x][y]='X';
        for(int i=0; i<4;i++){
            if(x+move[i][0]>=0 && x+move[i][0]<n && y+move[i][1]>=0 && y+move[i][1]<m && mat[x+move[i][0]][y+move[i][1]]=='O'){
                bfs(x+move[i][0], y+move[i][1], mat);
            }
        }
    }
    
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        char visited[n][m];
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                visited[i][j]=mat[i][j];
            }
        }
        
        for(int i=0; i<n; i++){
            bfs(i,0,mat);
            bfs(i,m-1,mat);
        }
        
        for(int j=0;j<m;j++){
            bfs(0,j,mat);
            bfs(n-1,j,mat);
        }
        
        for(int i=0; i<n;i++){
            for(int j=0; j<m; j++){
                if(visited[i][j]=='O'){
                    if(visited[i][j]!=mat[i][j]){
                        mat[i][j]='O';
                    }
                    else{
                        mat[i][j]='X';
                    }
                }
            }
        }
        
        return mat;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}  // } Driver Code Ends
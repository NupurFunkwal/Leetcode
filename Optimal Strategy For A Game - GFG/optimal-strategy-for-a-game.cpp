// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

//Function to find the maximum possible amount of money we can win.
class Solution{
    public:
    int dp[1001][1001];
    
    long long solve(int arr[], int i, int j){
        if(i>j){
            return 0;
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        if(i==j){
            return dp[i][j] = arr[i];
        }
        
        return dp[i][j] = max(arr[i]+min(solve(arr, i+2, j), solve(arr, i+1, j-1)), arr[j]+min(solve(arr,i, j-2),solve(arr, i+1, j-1)));
    }
    
    long long maximumAmount(int arr[], int n){
        //base case
        if(n==0){
            return 0;
        }
        if(n==2){
            return max(arr[0],arr[1]);
        }
        
        memset(dp, -1, sizeof(dp));
        return solve(arr, 0, n-1);
        
    }
};

// { Driver Code Starts.
int main() 
{
   
   	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		cout<< ob.maximumAmount(a,n)<<endl;
	}
	return 0;
}  // } Driver Code Ends
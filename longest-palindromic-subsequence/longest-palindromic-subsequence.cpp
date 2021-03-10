class Solution {
public:
    int LCS(string a, string b){
        int n = a.size();
        int m = b.size();
        int dp[n+1][m+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0 || j==0){
                    dp[i][j]=0;
                    continue;
                }
                if(a[i-1]==b[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
    int longestPalindromeSubseq(string s) {
        string a = s;
        reverse(s.begin(), s.end());
        return LCS(a,s);
    }
};
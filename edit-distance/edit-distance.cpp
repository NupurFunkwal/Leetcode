class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        int dp[n+1];
        // for(int i=0;i<=n;i++){
        //     dp[i][0]=i;
        // }
        for(int j=0;j<=n;j++){
            dp[j]=j;
        }
        for(int j=1;j<=m;j++){
            int prev = dp[0];
            dp[0] = j;
            for(int i=1;i<=n;i++){
                if(word1[i-1]==word2[j-1]){
                    int temp = prev;
                    prev = dp[i];
                    dp[i] = temp;
                }
                else{
                    int temp = prev;
                    prev = dp[i];
                    dp[i] = min(min(1+dp[i], 1 + temp), 1+dp[i-1]);
                }
            }
        }
        return dp[n];
    }
};
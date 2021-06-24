class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        
        if(n == 1){
            if(s[0] == '0'){
                return 0;
            }
            else return 1;
        }
        
        int dp[n+1];
        dp[0] = 1;
        if(s[0] != '0'){
            dp[1] = 1;
        }
        else dp[1] = 0;
        
        for(int i=2; i<=n; i++){
            if(s[i] == '0'){
               dp[i] = dp[i-1];
                continue;
            }
            int one = dp[i-1];
            if(s[i-1] == '0'){
                one = 0;
            }
            int two = 0;
            int num = stoi(s.substr(i-2,2));
            if( s[i-2] != '0' && num>= 1 &&  num<=26){
                two = dp[i-2];
            }
            dp[i] = one + two;
        }
           
        return dp[n];
    }
};
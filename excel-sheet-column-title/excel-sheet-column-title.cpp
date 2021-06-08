class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans="";
        int n = columnNumber;
        
        while(n){
            if(n%26 == 0){
                ans += 'Z';
                n = n/26 -1 ;
                continue;
            }
            ans = ans + (char)('A' + ((n%26) -1));
            n = n/26;
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};                                   
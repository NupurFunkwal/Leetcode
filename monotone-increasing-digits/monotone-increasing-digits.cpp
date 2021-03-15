class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        string ans = to_string(N);
        int n = ans.length();
        
        int p=1;
        while(p<n){
            if(ans[p]<ans[p-1]){
                break;
            }
            else{
                p++;
            }
        }
        if(p==n){
            return N;
        }
        
        int temp = p-1;
        ans[temp]--;
        
        while(p<n){
            ans[p]='9';
            p++;
        }
        while(temp>0 && ans[temp]<ans[temp-1]){
            ans[temp]='9';
            temp--;
            ans[temp]--;
        }
        
        int result = stoi(ans);
        return result;
    }
};
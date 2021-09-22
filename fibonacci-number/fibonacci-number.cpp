class Solution {
public:
    int fib(int n) {
        int a = 0;
        int b = 1;
        
        if(n ==0 || n==1){
            return n;
        }
        
        int cur = 2;
        int ans;
        while(cur<=n){
            ans = a+b;
            cur++;
            a = b;
            b = ans;
        }
        return ans;
    }
};
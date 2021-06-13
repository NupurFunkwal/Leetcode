class Solution {
public:
    int minSteps(int n) {
        if(n==2){
            return n;
        }
        
        int ans=0;
        int i = 2;
        
        while(n>1){
            while(n%i == 0){
                ans+= i;
                n/=i;
            }
            
            i++;
        }
        
        return ans;
    }
};
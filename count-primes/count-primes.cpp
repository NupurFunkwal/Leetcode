class Solution {
public:
    int countPrimes(int n) {
        n=n-1;
        if(n<2){
            return 0;
        }
        if(n==2){
            return 1;
        }
        int count=1;
        vector<bool> sieve(floor((n-3)/2+1),true);
        for(int i=0;i<sieve.size();i++){
            int p= 2*i+3;
            if(sieve[i]==true){
                count++;
            }
            
            for(long j=2*(long)i*(long)i+6*i+3;j<sieve.size();j+=p){
                sieve[j]=false;
            }
        }
        return count;
    }
};
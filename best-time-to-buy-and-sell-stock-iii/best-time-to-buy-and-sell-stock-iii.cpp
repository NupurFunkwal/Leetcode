class Solution {
public:
    
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int> left(n,0);
        vector<int> right(n,0);
        
        int maxprofit=0;
        int smallest=prices[0];
        for(int i=0;i<n;i++){
            if(prices[i]>=smallest){
                maxprofit=max(maxprofit, prices[i]-smallest);
            }
            else{
                smallest=prices[i];
            }
            left[i]=maxprofit;
        }
        
        maxprofit=0;
        int largest=prices[n-1];
        
        for(int i=n-1;i>=0;i--){
            if(prices[i]<=largest){
                maxprofit=max(maxprofit, largest-prices[i]);
            }
            else{
                largest=prices[i];
            }
            right[i]=maxprofit;
        }
        
        vector<int> partition(n,0);
        int maxval=0;
        for(int i=0;i<n;i++){
            if(i==0){
                partition[i]=right[i];
            }
            else{
                partition[i]=left[i-1]+right[i];
            } 
            maxval=max(maxval,partition[i]);
        }
        return maxval;
    }
};
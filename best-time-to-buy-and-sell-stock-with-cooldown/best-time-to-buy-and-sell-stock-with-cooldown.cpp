class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        //using state diagram
        //states-> held, sold, reset
        //value in each array represents max profit at that state
        
        int held[n+1], sold[n+1], reset[n+1];
        held[0] = INT_MIN, sold[0] = INT_MIN, reset[0] = 0;
        
        for(int i = 0; i<n; i++){
            sold[i+1] = held[i] + prices[i];
            held[i+1] = max(held[i], reset[i]-prices[i]);
            reset[i+1] = max(reset[i], sold[i]);
        }
       
        return max(sold[n], reset[n]);

    }
};
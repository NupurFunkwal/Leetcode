class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        vector<int> buy(n);
        vector<int> sell(n);
        
        for(int i=0; i<n; i++){
            buy[i] = max(i>0? buy[i-1] : -prices[0], (i-1>=2? sell[i-2] : 0) -prices[i]);
            sell[i] = max(i>0? sell[i-1]: 0, (i>0? buy[i-1]:-prices[0]) + prices[i]);
        }
        return sell[n-1];
    }
};
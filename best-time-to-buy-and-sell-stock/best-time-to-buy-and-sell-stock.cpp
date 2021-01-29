class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int mini=prices[0];
        int maxprofit=0;
        for(int i=1;i<n;i++){
            if(prices[i]>mini){
                maxprofit=max(maxprofit, prices[i]-mini);
            }
            else{
                mini=prices[i];
            }
        }
        return maxprofit;
    }
};
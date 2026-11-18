class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int ans=0, mini=INT_MAX;
        for(int price: prices){
            mini=min(mini, price);
            ans=max(ans, price-mini);
        }
        return ans;
    }
};
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // sliding window
        int l=0,r=0,ans=0,n=prices.size();
        while(r<n){
            if(prices[l]>prices[r]){
                l=r;
            }
            ans=max(ans,prices[r]-prices[l]);
            r++;
        }
        return ans;
    }
};

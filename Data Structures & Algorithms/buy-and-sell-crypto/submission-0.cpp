class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // dp approach
        int maxi=INT_MIN,ans=0,n=prices.size();
        for(int i=n-1;i>=0;i--){
            maxi=max(maxi,prices[i]);
            ans=max(ans,maxi-prices[i]);
        }
        return ans;
    }
};

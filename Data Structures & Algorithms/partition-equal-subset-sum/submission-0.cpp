class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int s=0;
        for(auto i:nums){
            s+=i;
        }
        if(s%2==1){
            return false;
        }
        s=s/2;
        vector<bool>dp(s+1,false);
        dp[0]=true;
        for(auto i:nums){
            // cout<<i<<endl;
            for(int j=s;j>=i;j--){
                dp[j]=dp[j]||dp[j-i];
            }
            // for(auto i:dp){
            //     cout<<i<<' ';
            // }
            // cout<<endl;
        }
        return dp[s];
    }
};

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
            for(int j=s;j>=i;j--){
                dp[j]=dp[j]||dp[j-i];
            }
        }
        return dp[s];
    }
};

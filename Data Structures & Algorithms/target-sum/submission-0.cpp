class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int s=0,n=nums.size();
        for(auto i:nums){
            s+=i;
        }
        if((s+target)%2==1){
            return 0;
        }
        int x=((s+target)/2);
        vector<int>dp(x+1,0);
        dp[0]=1;
        for(auto i:nums){
            for(int j=x;j>=i;j--){
                dp[j]+=dp[j-i];
            }
        }
        return dp[x];
    }
};

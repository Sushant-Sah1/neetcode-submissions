class Solution {
public:
    int rob(vector<int>& nums) {
        // gap of 1 is required
        // gap of 2 is fine 
        // gap of 3 or more watses houses.
        
        // need o acomodate gaps of 1/2

        // dp[i] -> max money i can take given i can accodomate house at position i or before
        // transition -> dp[i]=max(dp[i-1],dp[i-2]+nums[i])
        // if accomodate dp[i-1], can accodomate i house at all; 

        if(nums.size()==1){
            return nums[0];
        }
        nums[1]=max(nums[0],nums[1]);
        for(int i=2;i<nums.size();i++){
            nums[i]=max(nums[i-1],nums[i]+nums[i-2]);
        }
        return nums.back();
    }
};

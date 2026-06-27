class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size(),canidx=n-1;
        for(int i=n-1;i>=0;i--){
            if((canidx-i)<=nums[i]){
                canidx=i;
            }
        }
        return (canidx==0);
    }
};

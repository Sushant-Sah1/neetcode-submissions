class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        vector<int>t=nums;
        int n=nums.size();int ans=0;
        t[1%n]=max(t[0%n],t[1%n]);
        for(int i=2;i<n-1;i++){
            t[i%n]=max(t[(i-1+n)%n],t[i%n]+t[(i-2+n)%n]);
        }
        ans=max(ans,t[n-2]);
        t=nums;
        t[2%n]=max(t[1%n],t[2%n]);
        for(int i=3;i<n;i++){
            t[i%n]=max(t[(i-1+n)%n],t[i%n]+t[(i-2+n)%n]);
        }
        ans=max(ans,t[n-1]);
        return ans;
    }
};

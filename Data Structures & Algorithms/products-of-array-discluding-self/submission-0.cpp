class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>pref(n+2,1),suf(n+2,1);
        for(int i=0;i<n;i++){
            pref[i+1]=nums[i]*pref[i];
        }
        for(int i=n-1;i>=0;i--){
            suf[i+1]=nums[i]*suf[i+2];
        }
        vector<int>ans;
        for(int i=1;i<=n;i++){
            ans.push_back(pref[i-1]*suf[i+1]);
        }
        return ans;
    }
};

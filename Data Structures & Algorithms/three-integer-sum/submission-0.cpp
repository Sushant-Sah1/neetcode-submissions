class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<vector<int>>ans;
        int n=nums.size();
        for(int i=n-1;i>=0;i--){
            int l=0,r=i-1;
            while(l<r){
                // cout<<nums[l]<<' '<<nums[r]<<' '<<nums[i]<<endl;;
                if(nums[l]+nums[r]==-nums[i]){
                    ans.insert({nums[l],nums[r],nums[i]});
                    l++;
                    r--;
                }else if(nums[l]+nums[r]>-nums[i]){
                    r--;
                }else{
                    l++;
                }
            }
        }
        vector<vector<int>>res;
        for(auto i:ans){
            res.push_back(i);
        }
        return res;
    }
};

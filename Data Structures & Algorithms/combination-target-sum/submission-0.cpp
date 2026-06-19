class Solution {
public:
    void recur(vector<vector<int>>&ans,vector<int>&t,vector<int>& nums,int sum,int target,int idx){
        if(idx==nums.size()){
            return;
        }
        if(sum==target){
            ans.push_back(t);
            return;
        }
        if(sum>target){
            return;
        }
        recur(ans,t,nums,sum,target,idx+1);
        t.push_back(nums[idx]);
        recur(ans,t,nums,sum+nums[idx],target,idx);
        t.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        vector<int>t;
        recur(ans,t,nums,0,target,0);
        return ans;
    }
};

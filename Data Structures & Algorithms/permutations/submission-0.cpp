class Solution {
public:
    void recur(vector<vector<int>>&ans,vector<int>&x,int idx){
        if(idx==x.size()){
            ans.push_back(x);
            return;
        }
        for(int i=idx;i<x.size();i++){
            swap(x[idx],x[i]);
            recur(ans,x,idx+1);
            swap(x[idx],x[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        recur(ans,nums,0);
        return ans;
    }
};

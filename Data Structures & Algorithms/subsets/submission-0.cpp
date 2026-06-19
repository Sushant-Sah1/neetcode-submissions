class Solution {
public:
    void recur(vector<vector<int>>&ans,vector<int>&v,int idx,vector<int>&t){
        if(idx==v.size()){
            ans.push_back(t);
            return;
        }
        
        t.push_back(v[idx]);
        recur(ans,v,idx+1,t);
        t.pop_back();
        recur(ans,v,idx+1,t);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>t;
        recur(ans,nums,0,t);
        return ans;
    }
};

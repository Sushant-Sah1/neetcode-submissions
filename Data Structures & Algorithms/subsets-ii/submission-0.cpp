class Solution {
public:
    void recur(vector<vector<int>>&ans,vector<int>&v,map<int,int>&mp,vector<int>&t,int idx){
        if(idx==v.size()){
            ans.push_back(t);
            return;
        }
        for(int i=0;i<mp[v[idx]];i++){
            recur(ans,v,mp,t,idx+1);
            t.push_back(v[idx]);
        }
        recur(ans,v,mp,t,idx+1);
        for(int i=0;i<mp[v[idx]];i++){
            t.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>v;
        map<int,int>mp;
        vector<vector<int>>ans;
        for(auto i:nums){
            mp[i]++;
        }
        for(auto i:mp){
            v.push_back(i.first);
        }
        vector<int>t;
        recur(ans,v,mp,t,0);
        return ans;
    }
};

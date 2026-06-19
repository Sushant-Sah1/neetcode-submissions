class Solution {
public:
    void recur(vector<vector<int>>&ans,map<int,int>&mp,vector<int>&v,vector<int>&t,int target,int idx,int sum){
        if(sum==target){
            // cout<<sum<<' '<<target<<endl;
            ans.push_back(t);
            return;
        }
        if(sum>target){
            return;
        }
        if(idx==v.size()){
            return;
        }
        // cout<<sum<<' '<<target<<' '<<idx<<' '<<v.size()<<endl;
        int x=0;
        for(int i=0;i<mp[v[idx]];i++){
            recur(ans,mp,v,t,target,idx+1,sum+x);
            t.push_back(v[idx]);
            x+=v[idx];
        }
        recur(ans,mp,v,t,target,idx+1,sum+x);
        for(int i=0;i<mp[v[idx]];i++){
            t.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        map<int,int>mp;
        for(auto i:candidates){
            mp[i]++;
        }
        vector<int>v;
        for(auto i:mp){
            v.push_back(i.first);
        }
        vector<vector<int>>ans;
        vector<int>t;
        recur(ans,mp,v,t,target,0,0);
        return ans;
    }
};

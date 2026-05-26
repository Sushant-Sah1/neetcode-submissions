class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int,int>mp;
        for(auto i:nums){
            mp[i]++;
        }
        vector<pair<int,int>>v;
        for(auto i:mp){
            v.push_back({i.second,i.first});
        }
        sort(v.begin(),v.end());
        vector<int>ans;
        int n=v.size();
        for(int i=0;i<k;i++){
            ans.push_back(v[n-1-i].second);
        }
        return ans;
    }
};

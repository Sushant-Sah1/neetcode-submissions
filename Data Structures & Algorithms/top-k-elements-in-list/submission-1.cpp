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
        vector<int>ans;
        int n=v.size();


        // tc= nlogn; sc=n
        // sort(v.begin(),v.end());
        // for(int i=0;i<k;i++){
        //     ans.push_back(v[n-1-i].second);
        // }
        // return ans;
        
        // using minheap to track topk largest 
        // tc =nlogk , sc=(n+k)
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(auto i:v){
            if(pq.size()<k){
                pq.push(i);
            }else if(pq.top().first<i.first){
                pq.pop();
                pq.push(i);
            }
        }
        while(!pq.empty()){
            auto [x,y]=pq.top();
            pq.pop();
            ans.push_back(y);
        }
        return ans;
    }
};

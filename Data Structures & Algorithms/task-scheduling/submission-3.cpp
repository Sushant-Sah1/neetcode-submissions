class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>v(26,0);
        for(auto i:tasks){
            v[i-'A']++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        int ans=0;
        for(auto i:v){
            if(i>0){
                pq.push({1,i});
            }
        }
        while(!pq.empty()){
            auto [t,c]=pq.top();
            pq.pop();
            // cout<<t<<' '<<c<<' '<<ans<<endl;
            if(t<=ans){
                ans++;
            }else{
                ans=t;
            }
            c--;
            if(c>0){
                pq.push({t+n+1,c});
            }
        }
        return ans;
    }
};

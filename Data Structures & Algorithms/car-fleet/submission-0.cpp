class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>>v;
        int n=position.size();
        for(int i=0;i<n;i++){
            v.push_back({position[i],speed[i]});
        }
        sort(v.begin(),v.end());
        stack<pair<int,int>>stk;
        // for(auto i:v){
        //     cout<<i.first<<' '<<i.second<<"  -  ";
        // }
        // cout<<endl;
        stk.push(v[n-1]);
        for(int i=n-2;i>=0;i--){
            auto [p,s]=v[i];
            auto [tp,ts]=stk.top();
            // cout<<target<<' '<<tp<<' '<<ts<<' '<<p<<' '<<s<<endl;
            if(ts>=s){
                stk.push(v[i]);
            }else{
                int df=(tp-p),sf=(s-ts);
                int dt=(target-tp),st=ts;
                // cout<<df<<' '<<sf<<' '<<dt<<' '<<st<<' '<<(dt*sf)<<' '<<(st*df)<<endl;
                if((dt*sf)<(st*df)){
                    stk.push(v[i]);
                }
            }
            
        }
        return stk.size();
    }
};

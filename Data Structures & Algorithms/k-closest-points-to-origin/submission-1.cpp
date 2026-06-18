class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
       priority_queue<pair<double,int>>pq;
       for(int i=0;i<points.size();i++){
        int x=points[i][0],y=points[i][1];
        double d=sqrt((x*x)+(y*y));
        // cout<<x<<' '<<y<<' '<<d<<endl;
        if(pq.size()<k){
            pq.push({d,i});
        }else{
            if(d<pq.top().first){
                pq.pop();
                pq.push({d,i});
            }
        }
       }
       vector<vector<int>>ans;
       while(!pq.empty()){
        ans.push_back(points[pq.top().second]);
        pq.pop();
       }
       return ans;
    }
};

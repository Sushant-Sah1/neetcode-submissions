class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>>pq;
        vector<int>ans;
        int l=0,r=0;
        while(r<(k-1)){
            pq.push({nums[r],r});
            r++;
        }
        while(r<nums.size()){
            pq.push({nums[r],r});
            while(!pq.empty()){
                auto [x,y]=pq.top();
                // cout<<x<<' '<<y<<' '<<l<<endl;
                if(y>=l){
                    ans.push_back(x);
                    break;
                }else{
                    pq.pop();
                }
            }
            l++;
            r++;
        }
        return ans;
    }
};

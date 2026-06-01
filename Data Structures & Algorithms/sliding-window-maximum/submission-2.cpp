class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // using deque
        deque<pair<int,int>>q;
        int n=nums.size(),l=0,r=0;
        vector<int>ans;
        while(r<k-1){
            while(!q.empty()){
                if(q.back().first<nums[r]){
                    q.pop_back();
                }else{
                    break;
                }
            }
            q.push_back({nums[r],r});
            r++;
        }
        while(r<n){
            while(!q.empty()){
                if(q.back().first<nums[r]){
                    q.pop_back();
                }else{
                    break;
                }
            }
            q.push_back({nums[r],r});
            ans.push_back(q.front().first);
            l++;
            r++;
            if(q.front().second<l){
                q.pop_front();
            }
        }
        return ans;
    }
};

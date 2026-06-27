class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        sort(intervals.begin(),intervals.end());
        ans.push_back(intervals[0]);

        int n=intervals.size();
        for(int i=1;i<n;i++){
            vector<int>x=ans.back(),y=intervals[i];
            if(x[1]>=y[0]){
                ans.pop_back();
                ans.push_back({min(x[0],y[0]),max(x[1],y[1])});
            }else{
                ans.push_back(y);
            }
        }
        return ans;
    }
};

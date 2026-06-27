class Solution {
public:

    bool func(vector<vector<int>>&ans,vector<int>inter,bool tr){
        vector<int>x=ans.back();
        // cout<<x[0]<<' '<<x[1]<<" -> "<<inter[0]<<' '<<inter[1]<<' '<<tr<<endl;
        if(x[1]>=inter[0]){
            if(x[0]>inter[1]){
                ans.pop_back();
                ans.push_back(inter);
                ans.push_back(x);
                return true;
            }else{
                ans.pop_back();
                ans.push_back({min(x[0],inter[0]),max(inter[1],x[1])});
                return true;
            }
        }else{
            if(tr){
                ans.push_back(inter);
                return true;
            }
        }
        return false;
    }

    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>ans;
        if(intervals.size()==0){
            ans.push_back(newInterval);
            return ans;
        }

        
        ans.push_back(intervals[0]);

        bool tr=false;
        if(func(ans,newInterval,false)){
            tr=true;
        }

        for(int i=1;i<intervals.size();i++){
            func(ans,intervals[i],true);
            if(!tr){
                if(func(ans,newInterval,false)){
                    tr=true;
                }
            }
        }

        if(!tr){
            func(ans,newInterval,true);
        }

        return ans;
        
    }
};

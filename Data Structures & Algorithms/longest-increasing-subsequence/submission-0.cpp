class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        map<int,int>mp;
        mp[INT_MIN]=0;
        int ans=0;
        for(auto i:nums){
            int x=0;
            for(auto j:mp){
                if(j.first<i){
                    x=max(x,j.second);
                }else{
                    break;
                }
            }
            mp[i]=x+1;
            ans=max(ans,x+1);
        }
        return ans;
    }
};

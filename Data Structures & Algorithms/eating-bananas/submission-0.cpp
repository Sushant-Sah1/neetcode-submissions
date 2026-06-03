class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1,r=1,ans=1;
        for(auto i:piles){
            r=max(r,i);
            ans=r;
        }
        while(l<=r){
            int m=(l+r)/2;
            int c=0;
            for(auto i:piles){
                c+=(i+m-1)/m;
            }
            if(c>h){
                l=m+1;
            }else{
                r=m-1;
                ans=min(ans,m);
            }
        }
        return ans;
    }
};

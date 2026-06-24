class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int pp=0,np=0,ans=nums[0];
        for(auto i:nums){
            int nnp,npp;
            if(i>0){
                npp=max(pp*i,i);
                nnp=np*i;
            }else if(i<0){
                nnp=min(pp*i,i);
                npp=(np*i);
            }else{
                nnp=0;
                npp=0;
            }
            np=nnp;
            pp=npp;
            if(np!=0){
                ans=max(ans,np);
            }
            if(pp!=0){
                ans=max(ans,pp);
            }
            ans=max(ans,i);
        }
        return ans;
    }
};

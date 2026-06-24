class Solution {
public:
    int maxProduct(vector<int>& nums) {
        bool tr=false;
        for(auto i:nums){
            if(i==0){
                tr=true;
            }
        }
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
            // cout<<i<<' '<<np<<' '<<pp<<endl;
            if(np!=0){
                ans=max(ans,np);
            }else if(tr){
                ans=max(ans,np);
            }
            if(pp!=0){
                ans=max(ans,pp);
            }else if(tr){
                ans=max(ans,pp);
            }
        }
        return ans;
    }
};

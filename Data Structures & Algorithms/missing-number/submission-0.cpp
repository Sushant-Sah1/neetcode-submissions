class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ans=0;
        for(auto i:nums){
            ans=ans^i;
        }
        int n=nums.size();
        int net;
        if(n%4==0){
            net=n;
        }else if(n%4==1){
            net=1;
        }else if(n%4==2){
            net=n+1;
        }else{
            net=0;
        }
        return (ans^net);
    }
};

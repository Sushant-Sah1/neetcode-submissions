class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int>maxir(n,height[n-1]);
        for(int i=n-2;i>=0;i--){
            maxir[i]=max(height[i],maxir[i+1]);
        }
        int ans=0,maxil=0;
        for(int i=0;i<n;i++){
            maxil=max(maxil,height[i]);
            ans+=min(maxil,maxir[i])-height[i];   
        }
        return ans;
    }
};

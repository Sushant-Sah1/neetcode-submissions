class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        int n=nums.size(),i=n-1,ib=n;
        nums.push_back(1e7);
        while(i>=0){
            if(nums[i]!=nums[ib]){
                ib=i;
                int l=0,r=i-1;
                while(l<r){
                    // cout<<nums[l]<<' '<<nums[r]<<' '<<nums[i]<<endl;;
                    if(nums[l]+nums[r]==-nums[i]){
                        ans.push_back({nums[l],nums[r],nums[i]});
                        int lb=l,rb=r;
                        while(l<n){
                            if(nums[l]==nums[lb]){
                                l++;
                            }else{
                                break;
                            }
                        }
                        while(r>=0){
                            if(nums[r]==nums[rb]){
                                r--;
                            }else{
                                break;
                            }
                        }
                    }else if(nums[l]+nums[r]>-nums[i]){
                        r--;
                    }else{
                        l++;
                    }
                }
            }
            i--;
        }
        return ans;
    }
};

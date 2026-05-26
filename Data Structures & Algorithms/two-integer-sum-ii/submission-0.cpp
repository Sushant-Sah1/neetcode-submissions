class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l=0,r=numbers.size()-1;
        while(l<r){
            int x=numbers[l]+numbers[r];
            if(x==target){
                return {l+1,r+1};
            }else if(x<target){
                l++;
            }else{
                r--;
            }
        }
    }
};

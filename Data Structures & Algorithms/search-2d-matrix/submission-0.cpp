class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int ri=-1;
        int l=0,r=matrix.size()-1;
        while(l<=r){
            int m=(l+r)/2;
            if(matrix[m][0]>target){
                r=m-1;
            }else if(matrix[m][matrix[0].size()-1]<target){
                l=m+1;
            }else{
                ri=m;
                break;
            }
        }
        if(ri==-1){
            return false;
        }
        l=0,r=matrix[ri].size()-1;
        int ci=-1;
        while(l<=r){
            int m=(l+r)/2;
            if(matrix[ri][m]>target){
                r=m-1;
            }else if(matrix[ri][m]<target){
                l=m+1;
            }else{
                ci=m;
                break;
            }
        }
        if(ci==-1){
            return false;
        }
        return true;
    }
};

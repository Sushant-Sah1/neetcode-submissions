class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int ca=0,cb=0,cc=0;
        for(auto i:triplets){
            if(i[0]<=target[0] && i[1]<=target[1] && i[2]<=target[2]){
                ca=max(ca,i[0]);
                cb=max(cb,i[1]);
                cc=max(cc,i[2]);
            }
        }
        return (ca==target[0] && cb==target[1] && cc==target[2]);
    }
};

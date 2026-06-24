class Solution {
public:
    int climbStairs(int n) {
        int prev=1,cur=1;
        for(int i=2;i<=n;i++){
            int t=cur+prev;
            prev=cur;
            cur=t;
        }
        return cur;
    }
};

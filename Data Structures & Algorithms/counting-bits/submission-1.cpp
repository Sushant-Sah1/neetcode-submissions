class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>ans={0};
        for(int i=1;i<=n;i++){

            // operation :- i&(i-1) clears out lowest set bit from i and bits 
            // of i . eg i=10110 , then this op gives 10110 & 10101 => 10100.
            // if we know bits of i&(i-1) we can get bits of i. 
            // note i&(i-1) is always smaller than i

            ans.push_back(ans[i&(i-1)]+1);
        }
        return ans;
    }
};

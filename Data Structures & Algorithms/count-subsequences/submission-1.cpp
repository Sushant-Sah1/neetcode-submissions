class Solution {
public:
    int numDistinct(string s, string t) {
        int n=s.size(),m=t.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        // base case is important
        // if t=="" then any out of any s , only valid subsequence will be s==""
        for(int i=0;i<=n;i++){
            dp[i][0]=1;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                // note tht dp state is number subsubsequences in s which are equal to t
                // so if s[i-1]!=t[j-1] , thenwe cant use dp[...][j-1] cuz we need equal till j not (j-1) in dp state
                // also note that subsequences till i also must include all prev i for given j 
                dp[i][j]+=dp[i-1][j];

                // noteif equal , we need number of subsequnce in s(exlucding current i index) which are equal to
                //  elements in t till (j-1) cuz jth index is with ith index of s
                if(s[i-1]==t[j-1]){
                    dp[i][j]+=dp[i-1][j-1];
                }
            }
        }
        return dp[n][m];
    }
};

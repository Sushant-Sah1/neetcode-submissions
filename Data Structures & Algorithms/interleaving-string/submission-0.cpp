class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        // we can think about greedy , but get stuck at case where s1[i]==s2[j],
        //  NOW WHICH TO TAKE ?? WE MIGHT TAKE ONE , BUT NEED NEXT ELEMENTS OF OTHER 
        // SO DP
        int n=s1.size(),m=s2.size(),k=s3.size();
        if(n+m!=k){
            return false;
        }
        vector<vector<bool>>dp(n+1,vector<bool>(m+1,false));
        dp[0][0]=true;
        for(int i=1;i<=n;i++){
            if(s1[i-1]==s3[i-1]){
                dp[i][0]=true;
            }else{
                break;
            }
        }
        for(int i=1;i<=m;i++){
            if(s2[i-1]==s3[i-1]){
                dp[0][i]=true;
            }else{
                break;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s3[i+j-1]){
                    dp[i][j]=dp[i][j]||dp[i-1][j];
                }
                if(s2[j-1]==s3[i+j-1]){
                    dp[i][j]=dp[i][j]||dp[i][j-1];
                }
            }
        }
        return dp[n][m];
    }
};

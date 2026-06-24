class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int>dp(s.size()+1,false);
        dp[s.size()]=true;
        int n=s.size();
        for(int i=n-1;i>=0;i--){
            for(auto j:wordDict){
                if(j.size()<=(n-i)){
                    bool tr=true;
                    for(int k=0;k<j.size();k++){
                        if(j[k]!=s[i+k]){
                            tr=false;
                            break;
                        }
                    }
                    if(tr && dp[i+j.size()]){
                        dp[i]=true;
                    }
                }
            }
        }
        return dp[0];
    }
};

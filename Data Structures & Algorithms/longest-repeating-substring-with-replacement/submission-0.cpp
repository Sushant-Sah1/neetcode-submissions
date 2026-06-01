class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int>v(26,0);
        int l=0,r=0,ans=0,t=0,n=s.size();
        while(r<n){
            v[s[r]-'A']++;
            while(true){
                int len=(r-l+1);
                int mini=len;
                for(auto i:v){
                    mini=min(mini,len-i);
                }
                // cout<<len<<' '<<mini<<' '<<l<<endl;
                if(mini<=k){
                    break;
                }else{
                    v[s[l]-'A']--;
                    l++;
                }
            }
            // cout<<l<<' '<<r<<' '<<(r-l+1)<<endl<<endl;;
            ans=max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};

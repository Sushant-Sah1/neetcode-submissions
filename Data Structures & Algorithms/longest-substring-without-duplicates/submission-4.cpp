class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // if(s.empty()){
        //     return 0;
        // }
        // vector<bool>v(26,false);
        unordered_map<char,int>v;
        int l=0,r=0,t=0,ans=0,n=s.size();
        while(r<n){
            while(v[s[r]-'a']>0){
                v[s[l]-'a']=false;
                l++;
            }
            v[s[r]-'a']=1;
            ans=max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};

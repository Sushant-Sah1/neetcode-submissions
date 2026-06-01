class Solution {
public:
    string minWindow(string s, string t) {
        int ansl=-1,ansr=10000;
        int l=0,r=0,n=s.size(),k=0;
        map<char,int>mpt,mps;
        for(auto i:t){
            mpt[i]++;
        }
        for(auto i:mpt){
            k++;
        }
        while(r<n){
            mps[s[r]]++;
            if(mps[s[r]]==mpt[s[r]]){
                k--;
            }
            // cout<<r<<' '<<l<<' '<<k<<endl;
            while(k==0){
                // if(t==0){
                if(ansr-ansl>r-l){
                    ansr=r;
                    ansl=l;
                }
                // }
                mps[s[l]]--;
                if(mps[s[l]]==mpt[s[l]]-1){
                    k++;
                }
                l++;
            }
            r++;
        }
        // cout<<ansl<<' '<<ansr<<endl;
        if(ansl==-1){
            return "";
        }
        string ans="";
        for(int i=ansl;i<=ansr;i++){
            ans+=s[i];
        }
        
        return ans;
    }
};

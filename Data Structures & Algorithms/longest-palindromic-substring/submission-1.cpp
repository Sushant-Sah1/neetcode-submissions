class Solution {
public:
    string longestPalindrome(string s) {
        int al=-1,ar=-2,n=s.size();
        for(int i=0;i<n;i++){
            int l=i,r=i;
            while(l>=0 && r<n){
                if(s[l]==s[r]){
                    if((r-l+1)>(ar-al+1)){
                        ar=r;
                        al=l;
                    }
                }else{
                    break;
                }
                l--;
                r++;
            }
        }
        for(int i=0;i<n-1;i++){
            int l=i,r=i+1;
            while(l>=0 && r<n){
                if(s[l]==s[r]){
                    if((r-l+1)>(ar-al+1)){
                        ar=r;
                        al=l;
                    }
                }else{
                    break;
                }
                l--;
                r++;
            }
        }
        string ans="";
        for(int i=al;i<=ar;i++){
            ans+=s[i];
        }
        return ans;
    }
};

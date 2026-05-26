class Solution {
public:
    bool isPalindrome(string s) {
        string pal="";
        for(auto i:s){
            if(isalnum(i)){
                pal+=tolower(i);
            }
        }
        string t=pal;
        reverse(t.begin(),t.end());
        cout<<t<<endl<<pal<<endl;
        for(int i=0;i<t.size();i++){
            if(t[i]!=pal[i]){
                return false;
            }
        }
        return true;
    }
};

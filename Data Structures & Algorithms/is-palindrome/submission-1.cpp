class Solution {
public:
    bool isPalindrome(string s) {
        // string pal="";
        vector<char>pal;
        for(auto i:s){
            if(isalnum(i)){
                pal.push_back(tolower(i));
            }
        }
        // for(auto i:pal){
        //     cout<<i;
        // }
        int i=0,j=pal.size()-1;
        while(i<j){
            if(pal[i]!=pal[j]){
                return false;
            }
            i++;j--;
        }
        // string t=pal;
        // reverse(t.begin(),t.end());
        // cout<<t<<endl<<pal<<endl;
        // for(int i=0;i<t.size();i++){
        //     if(t[i]!=pal[i]){
        //         return false;
        //     }
        // }
        return true;
    }
};

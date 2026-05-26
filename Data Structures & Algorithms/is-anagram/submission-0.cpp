class Solution {
public:
    bool isAnagram(string s, string t) {
        int a[26]={0};
        for(auto i:s){
            a[(i-'a')]++;
            // cout<<(i-'a');
        }
        for(auto i:t){
            a[(i-'a')]--;
        }
        for(auto i:a){
            if(i!=0){
                return false;
            }
        }
        return true;
    }
};

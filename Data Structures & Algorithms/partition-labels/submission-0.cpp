class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int>ans;
        vector<int>t(26,0),c(26,0);
        for(auto i:s){
            t[i-'a']++;
        }
        int count=0;
        for(auto i:s){
            c[i-'a']++;
            count++;
            bool tr=true;;
            for(int i=0;i<26;i++){
                if(c[i]!=0 && c[i]!=t[i]){
                    tr=false;
                    break;
                }
            }
            if(tr){
                ans.push_back(count);
                count=0;
                for(int i=0;i<26;i++){
                    c[i]=0;
                }
            }
        }
        return ans;
    }
};

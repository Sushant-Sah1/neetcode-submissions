class Solution {
public:
    void recur(vector<vector<string>>&ans,vector<string>&v,string&s,string&cur,int idx){
        if(idx==s.size()){
            v.push_back(cur);
            bool tr=true;
            for(auto i:v){
                int l=0,r=i.size()-1;
                while(l<=r){
                    if(i[l]!=i[r]){
                        tr=false;
                        break;
                    }
                    l++;
                    r--;
                }
            }
            if(tr){
                ans.push_back(v);
            }
            v.pop_back();
            return;
        }
        cur+=s[idx];
        recur(ans,v,s,cur,idx+1);
        cur.pop_back();
        string t=cur;
        v.push_back(t);
        cur=s[idx];
        recur(ans,v,s,cur,idx+1);
        v.pop_back();
        cur=t;

    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>v;
        string cur="";
        cur+=s[0];
        recur(ans,v,s,cur,1);
        return ans;
    }
};

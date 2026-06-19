class Solution {
public:
    void recur(vector<string>&ans,int o,int c,string&s){
        if(o==0 && c==0){
            ans.push_back(s);
            return;
        }
        if(o<c){
            if(o>0){
                s+='(';
                recur(ans,o-1,c,s);
                s.pop_back();
            }
            s+=')';
            recur(ans,o,c-1,s);
            s.pop_back();
        }else{
            s+='(';
            recur(ans,o-1,c,s);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string s="";
        vector<string>ans;
        recur(ans,n,n,s);
        return ans;
    }
};

class Solution {
public:
    void recur(vector<string>&v,string&s,string&t,vector<string>&ans,int idx){
        if(idx==s.size()){
            ans.push_back(t);
            return;
        }
        for(auto i:v[s[idx]-'2']){
            t+=i;
            recur(v,s,t,ans,idx+1);
            t.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0){
            return {};
        }
        vector<string>v={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        string t="";
        vector<string>ans;
        recur(v,digits,t,ans,0);
        return ans;
    }
};

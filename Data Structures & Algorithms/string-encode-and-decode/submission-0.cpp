class Solution {
public:

    string encode(vector<string>& strs) {
        string ans="";
        for(auto i:strs){
            int n=i.size();
            string x=to_string(n);
            // while(n>0){
            //     x+=((n%10));
            //     n=n/10;
            // }
            // reverse(x.begin(),x.end());
            x+='.';
            ans+=x;
            ans+=i;
        }
        // cout<<ans<<endl;
        return ans;
    }

    vector<string> decode(string s) {
        vector<string>ans;
        int i=0,num=0;
        // cout<<endl;
        // cout<<s<<endl;
        while(i<s.size()){
            // cout<<i<<' '<<s[i]<<endl;
            if(s[i]!='.'){
                num=num*10+(s[i]-'0');
                // cout<<i<<' '<<s[i]<<' '<<(s[i]-'0')<<' '<<num<<endl;
                i++;
            }else{
                // cout<<num<<' ';
                i++;
                string x="";
                for(int j=0;j<num;j++){
                    x+=s[i];
                    i++;
                }
                // cout<<x<<endl;
                num=0;
                ans.push_back(x);
            }
        }
        return ans;
    }
};

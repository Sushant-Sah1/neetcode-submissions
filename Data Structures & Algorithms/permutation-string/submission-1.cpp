class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n=s2.size(),m=s1.size();
        if(m>n){
            return false;
        }
        vector<int>v(26,0);
        for(auto i:s1){
            v[i-'a']++;
        }
        for(int i=0;i<m;i++){
            v[s2[i]-'a']--;
        }
        int t=0;
        for(auto i:v){
            if(i!=0){
                t++;
            }
        }
        if(t==0){
            return true;
        }
        // for(auto i:v){
        //     cout<<i<<' ';
        // }
        // cout<<endl;
        // cout<<"I_>"<<' '<<t<<endl;
        for(int i=m;i<n;i++){
            v[s2[i-m]-'a']++;
            if(v[s2[i-m]-'a']==0){
                t--;
            }else if(v[s2[i-m]-'a']==1){
                t++;
            }
            v[s2[i]-'a']--;
            if(v[s2[i]-'a']==0){
                t--;
            }else if(v[s2[i]-'a']==-1){
                t++;
            }
            // for(auto i:v){
            //     cout<<i<<' ';
            // }
            // cout<<endl;
            // cout<<"I_>"<<i<<' '<<t<<endl;
            if(t==0){
                return true;
            }
            
        }
        return false;
    }
};

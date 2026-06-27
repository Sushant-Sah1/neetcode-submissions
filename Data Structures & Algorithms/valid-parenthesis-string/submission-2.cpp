class Solution {
public:
    bool checkValidString(string s) {
        int t=0,nu=0,uc=0,uo=0;
        for(auto i:s){
            if(i=='('){
                t++;
            }else if(i=='*'){
                if(t>0){
                    uc++;
                    t--;
                }else if(t<0){
                    return false;
                }else{
                    nu++;
                }
            }else{
                if(t>0){
                    t--;
                }else if(t<0){
                    return false;
                }else{
                    if(uc>0){
                        nu++;
                        uc--;
                    }else if(nu>0){
                        nu--;
                        uo++;
                    }else{
                        return false;
                    }
                }
            }
        }
        return (t==0);
    }
};

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for(auto i:tokens){
            if(i=="+"){
                int x=st.top();
                st.pop();
                int y=st.top();
                st.pop();
                st.push(y+x);
            }else if(i=="-"){
                int x=st.top();
                st.pop();
                int y=st.top();
                st.pop();
                st.push(y-x);
            }else if(i=="*"){
                int x=st.top();
                st.pop();
                int y=st.top();
                st.pop();
                st.push(y*x);
            }else if(i=="/"){
                int x=st.top();
                st.pop();
                int y=st.top();
                st.pop();
                st.push(y/x);
            }else{
                int x=0;
                bool sign=(i[0]=='-');
                for(int j=sign;j<i.size();j++){
                    x=x*10+(i[j]-'0');
                }
                if(sign){
                    x=-x;
                }
                st.push(x);
            }
            // cout<<st.top()<<endl;
        }
        return st.top();
    }
};

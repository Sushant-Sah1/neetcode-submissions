class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int>st;
        int n=temperatures.size();
        vector<int>ans;
        for(int i=n-1;i>=0;i--){
            int x=temperatures[i];
            while(!st.empty()){
                if(temperatures[st.top()]>x){
                    break;
                }else{
                    st.pop();
                }
            }
            if(st.empty()){
                ans.push_back(0);
            }else{
                ans.push_back(st.top()-i);
            }
            st.push(i);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

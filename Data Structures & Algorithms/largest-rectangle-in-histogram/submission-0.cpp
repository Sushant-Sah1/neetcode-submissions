class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int>st;
        st.push(-1);
        int ans=INT_MIN;
        int n=heights.size();
        for(int i=0;i<n;i++){
            // cout<<"I_>"<<i<<' '<<heights[i]<<' '<<st.size()<<' '<<st.top()<<endl;
            while(st.top()!=-1){
                int x=st.top();
                if(heights[x]>=heights[i]){
                    st.pop();
                    ans=max(ans,heights[x]*(i-st.top()-1));
                    // cout<<heights[x]<<' '<<i<<' '<<st.top()<<' '<<(heights[x]*(i-st.top()-1))<<endl;
                }else{
                    break;
                }
            }
            // cout<<"psuinh->"<<i<<endl;
            st.push(i);
            // cout<<ans<<endl;
        }
        // cout<<endl;
        // cout<<st.top()<<endl;
        while(st.top()!=-1){
            int x=st.top();
            st.pop();
            // cout<<heights[x]<<' '<<n<<' '<<st.top()<<' '<<(heights[x]*(n-st.top()-1))<<endl;
            ans=max(ans,heights[x]*(n-st.top()-1));
            // cout<<ans<<endl;
        }
        return ans;
    }
};

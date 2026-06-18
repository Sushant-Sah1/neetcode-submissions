class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>>pq;
    int max;
    KthLargest(int k, vector<int>& nums) {
        max=k;
        for(auto i:nums){
            if(pq.size()<k){
                pq.push(i);
            }else{
                if(i>pq.top()){
                    pq.pop();
                    pq.push(i);
                }
            }
        }
    }
    
    int add(int val) {
        if(pq.size()<max){
            pq.push(val);
        }else{
            if(val>pq.top()){
                pq.pop();
                pq.push(val);
            }
        }
        return pq.top();
    }
};

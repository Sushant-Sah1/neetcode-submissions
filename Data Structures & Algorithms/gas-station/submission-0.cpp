class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // total gas >= total cost
        // iterate and take sum , if at any point we have -ve value 
        // , then we cant start from beginning of sum to that point
        // move ptr for begging to next to it and start sum again 
        // just need to be 1 loop as it is confirmed if gas>=cost
        // then there must be 1 start point must

        int sum=0,l=0,n=gas.size();
        for(int i=0;i<n;i++){
            sum+=(gas[i]-cost[i]);
        }
        if(sum<0){
            return -1;
        }
        sum=0;
        for(int i=0;i<n;i++){
            sum+=(gas[i]-cost[i]);
            if(sum<0){
                l=(i+1)%n;
                sum=0;
            }
        }
        return l;

    }
};

/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        vector<vector<int>>inter;
        for(auto i:intervals){
            inter.push_back({i.start,i.end});
        }
        sort(inter.begin(),inter.end());
        int cur=INT_MIN,n=inter.size();
        for(int i=0;i<n;i++){
            if(inter[i][0]<cur){
                return false;
            }else{
                cur=inter[i][1];
            }
        }
        return true;
    }
};

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(),intervals.end());
        int high = intervals[0][1];
        int ans = 0 ;
        for(int i = 1 ; i < n ; i++){
            if(intervals[i][0]<high){
                high = min(intervals[i][1],high);
                ans++;
            }
            else{
                high = max(intervals[i][1],high);
            }
        }
        return ans;
    }
};
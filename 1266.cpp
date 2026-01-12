class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        vector<int> first = points[0];
        int n = points.size();
        int ans = 0;
        for(int i = 1 ; i < n ; i++){
            int x = points[i][0];
            int y = points[i][1];
            ans += max(abs(first[0] - x ) , abs(first[1] - y));  
            first[0] = x;
            first[1] = y;
        }
        return ans;
    }
};
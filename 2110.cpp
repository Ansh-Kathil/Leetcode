class Solution {
public:

    long long getDescentPeriods(vector<int>& prices) {
        long long ans = 0;
        for(int i = 0 ; i < prices.size();i++){
            long long  count = 1;
            ans += count;
            while( i + 1 < prices.size() &&  (prices[i] == prices[i+1] +1)){
                i++;
                ans += ++count;     
            }
            
        }
        return ans;
    }
};
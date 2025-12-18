class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();
        long long profit =  0;
         
        for(int i = 0 ; i < n ; i++){
            profit += 1LL * prices[i]*strategy[i];
        }
        long long delta = 0;
       
        for(int i = 0 ; i < k/2 ; i++){
            delta += 1LL * prices[i]* (0 - strategy[i]);
        }
        for(int i = k/2 ; i < k ; i++){
            delta += 1LL * prices[i]* (1 - strategy[i]);
        }
        
        long long ans =max(profit+delta,profit);

        for(int i = 1 ; i+k -1 < n ; i++){
            int r = i+k-1;
        
            delta -= 1LL * prices[i-1]* (0 - strategy[i-1]);
            delta -= 1LL * prices[i-1 +k/2]* (1 - strategy[i-1 + k/2]);

            delta += 1LL * prices[i+k/2-1]* (0 - strategy[i+k/2 - 1 ]);
            delta += 1LL * prices[r]* (1 - strategy[r]);
    
        ans = max(ans,profit+delta);
        }
        return ans;
    }
};
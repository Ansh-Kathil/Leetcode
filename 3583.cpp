class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const long long MOD = 1000000007LL;
        int n = nums.size();

    
        unordered_map<int,long long> full;
        unordered_map<int,long long> half; 
        for (int x : nums) full[x]++;

        long long count = 0;
        for (int j = 0; j < n; ++j) {
            int val = nums[j];
            full[val]--;

            long long target = 2LL * val;
        
            if (half.find(target) != half.end() && full.find(target) != full.end()) {
                count = (count + (half[target] * full[target]) % MOD) % MOD;
            }
            half[val]++;
        }

        return (int)count;
    }

};
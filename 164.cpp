class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return 0;

        int minval = *min_element(nums.begin(), nums.end());
        int maxval = *max_element(nums.begin(), nums.end());
        if (minval == maxval) return 0;


        long long range = (long long)maxval - minval;
        long long bucketSize = max(1LL, (range + (n - 2)) / (n - 1)); 
        long long bucketscount = range / bucketSize + 1;


        vector<long long> bucketMin(bucketscount, LLONG_MAX);
        vector<long long> bucketMax(bucketscount, LLONG_MIN);
        vector<char> used(bucketscount, 0);


        for (int x : nums) {
            long long idx = (x - minval) / bucketSize;
            if (idx >= bucketscount) idx = bucketscount - 1; 
            used[idx] = 1;
            if (x < bucketMin[idx]) bucketMin[idx] = x;
            if (x > bucketMax[idx]) bucketMax[idx] = x;
        }

        
        long long prevMax = -1;
        long long result = 0;
        for (long long i = 0; i < bucketscount; ++i) {
            if (!used[i]) continue; 
            if (prevMax != -1) {
                result = max(result, bucketMin[i] - prevMax);
            }
            prevMax = bucketMax[i];
        }

        return (int)result;
    }
};

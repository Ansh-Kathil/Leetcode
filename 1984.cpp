class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int ans = INT_MAX;
       
        for(int i = 0 ; i <= n-k ;i++){
            int maxi = INT_MIN;
            int mini =INT_MAX;
           
            for(int j = 0 ; j < k ; j++){
                mini = min(mini,nums[i+j]);
                maxi = max(maxi,nums[i+j]);
            }
            int diff = maxi-mini;
            ans = min(diff,ans);
        }
        return ans;

    }
};
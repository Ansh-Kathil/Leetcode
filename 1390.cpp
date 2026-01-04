class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0 ;
        int n = nums.size();
        int ind = 0;
        for(int i = 0 ; i < n ; i++){
            int count = 0;
            int sum = 0; 
            for(int j = 1 ; j <= nums[i] ;j++){
                if(nums[i]%j==0){
                    sum+=j;
                    count++;
                }
                if(count>4){
                    break;
                }
            }
            if(count==4){
                ans += sum;
                
            }
        }
        return ans;
    }
};
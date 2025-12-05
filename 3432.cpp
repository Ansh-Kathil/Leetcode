class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int right = 0 ; 
        for(int i : nums){
            right += i;
        }
        int left = 0 ;
        int count = 0 ;
        for(int i = 0  ; i < nums.size() - 1 ; i++){
            left += nums[i] ; 
            right -= nums[i] ;
            if((left-right)%2==0){
                count++;
            }
        }
        return count; 
    }
};
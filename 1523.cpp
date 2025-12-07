class Solution {
public:
    int countOdds(int low, int high) {
        long long  diff = (long long)high - (long long)low + 1 ;
        
        if(diff % 2 == 0){
            return diff/2;
        }
        else if(high % 2 == 0 ){
            return diff/2 ;
        }
        return diff/2 + 1;
    }
};
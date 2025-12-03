class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i = digits.size() - 1;
        digits[i]++;
        while( i >= 0 && digits[i] == 10){
            digits[i] = 0;
           
            if(i-1 >= 0){
                digits[i-1]++;
            }
            i--;
        }
        if(i==-1){
            digits.insert(digits.begin(),1);
        }
        return digits;


    }
};
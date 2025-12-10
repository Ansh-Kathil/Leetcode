class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        int mini = INT_MAX;
        int ind = -1;
        long long n = complexity.size();
        for(long long i = 0 ; i < n ; i++){
            if(complexity[i] <= mini){
                mini = complexity[i];
                ind = i;
            }
            
        }
        if(ind != 0){
            return 0;
        }
        long long mod = 1000000007;
        long long  fact = 1;
        for(long long i = 1 ; i <=n-1 ;i++){
            fact = (fact*i)%mod;
        }
        return fact;
    }
};
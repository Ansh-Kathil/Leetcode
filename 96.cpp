class Solution {
public:
    long long fact(long long n){
        if(n == 1 ){
            return 1;
        }
        return n * fact(n-1);
    }
    int numTrees(int n) {
        long long res = 1;
        for (int i = 0; i < n; i++) {
            res = res * 2 * (2 * i + 1) / (i + 2);
        }
        return res;
    }
};
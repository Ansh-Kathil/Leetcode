class Solution {
public:
    int numberOfWays(string corridor) {
        int freq = count(corridor.begin(), corridor.end(), 'S');
        
        if(freq == 2){
            return 1;
        }
        else if(freq %2 != 0 || freq == 0 ){
            return 0;
        } 
        const int MOD = 1e9 + 7;
        bool flag = 0;
        long long  ans = 1;
        int left = 0;
        for(int i = 0 ; i < corridor.size() ; i++){
            
            if(corridor[i] == 'S'){
                left++;
            }
            if(left==2){
                flag = 1 ;     
            }
            if(flag){
                flag = 0;
                left = 0 ; 
                long long  rand=1;
                while(i+1 < corridor.size() && corridor[i+1]=='P'){
                   
                    rand++;
                    i++;
                }
            
                if(!(i+1==corridor.size())){
                    
                    ans = (ans * rand )% MOD;
                }
            }
        }
       

        return ans;
    }
};
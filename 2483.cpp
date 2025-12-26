
class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.length();
        int county = 0 ; 
        for(char i : customers){
            if(i=='Y'){
                county++;
            }
        }
        int ind = 0;
        int mini = county;
        for(int i = 0 ; i < n; i++){
            if(customers[i]=='Y'){
                county--;
                if(mini>county){
                    mini = county;
                    ind = i+1;
                }
            }
            else{
                county++;
            }
        }
        return ind ;
    }
};

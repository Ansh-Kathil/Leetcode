class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        int n = code.size();
        vector<string> s = {"electronics", "grocery", "pharmacy", "restaurant"};
        
        vector<vector<string>> ans(4);
        for(int i = 0 ; i < 4 ; i++){
            for(int j = 0 ; j < n ; j++){
                if(businessLine[j] != s[i] || !isActive[j] ){
                    continue;
                }
                bool flag = 0;
                if(code[j] == ""){
                    flag = 1 ; 
                }
                for(char c : code[j]){
                    if(!isalnum(c) && c != '_'){
                        flag = 1;
                    }
                }
                if(flag == 0){
                    
                    ans[i].push_back(code[j]);
                }

            }
        }
         
        for (auto &row : ans) {
            sort(row.begin(), row.end());
        }
        vector<string> flat;
        for (const auto& row : ans) {
            for (string x : row) {
                flat.push_back(x);
            }
        }
       

        return flat;

    }
};
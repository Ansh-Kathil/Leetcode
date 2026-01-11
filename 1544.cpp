class Solution {
public:
    int minInsertions(string s) {
        int insert =  0;
        stack<char> sta;
        for(int i = 0 ; i < s.length() ;i++){
            if(s[i] == '('){
                sta.push('(');
            }
            else{
                if(sta.empty()){
                    insert++;
                    sta.push('(');
                    i--;
                }
                else{
                    sta.pop();
                    if( i + 1 >= s.length() || s[i+1] == '('){
                        insert++;
                    }
                    else{
                        i++;
                    }

                }

            }
        }

        return insert + 2*sta.size();
    }
};
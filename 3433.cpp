class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        vector<int> ans(numberOfUsers,0);
        vector<int> offline(numberOfUsers,-1);

        sort(events.begin(), events.end(),
            [](const auto &a, const auto &b) {
                int ta = stoi(a[1]);
                int tb = stoi(b[1]);

                if (ta != tb)
                    return ta < tb;             

                return a[0] > b[0];              
            });
        
        for(auto &i : events){
            if(i[0][0] == 'M'){
                if(i[2][0] == 'A'){
                    for(int &x : ans) x++;
                }
                else if(i[2][0] == 'H'){
                    for(int j = 0 ; j < numberOfUsers ; j++){
                        if(offline[j] == -1){
                            ans[j]++;
                        }
                        else if(offline[j] + 60 <= stoi(i[1]) ){
                            ans[j]++;
                            offline[j] = -1;
                        }
                    }
                }
                else{
                    for(int j = 2 ; j < i[2].size(); j = j +  3){
                        string c ="";
                        while(j < i[2].size() &&  i[2][j] != ' '){
                            c += i[2][j++];
                        }
                        cout<<c<<endl;
                        ans[stoi(c)]++;
                    }                    
                }
            }
            else{
                offline[stoi(i[2])] = stoi(i[1]);

            }
        }
        return ans;
    }
};
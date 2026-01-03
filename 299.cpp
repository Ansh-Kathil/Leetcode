class Solution {
public:
    string getHint(string secret, string guess) {
        int b = 0;
        int n = guess.size();
        unordered_map<char,int> mp;
        for(int i = 0 ; i < n ; i++){
            if(secret[i] == guess[i]){
                b++;
                guess[i] = 'a';
            }
            else{
                mp[secret[i]]++;
            }
        }
        int count = 0;
        for(int i = 0 ; i <n ;i++){
            if(mp.find(guess[i]) != mp.end()){
                mp[guess[i]]--;
                count++;
                if(mp[guess[i]] == 0){
                    mp.erase(guess[i]);
                }
            }
        }
        string s = to_string(b) + "A" + to_string(count) + "B";
        return s ; 

    }
};
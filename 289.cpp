class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> update = board;
        int n = board.size();
        int m = board[0].size();
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m;j++){
                int lives = 0 ;
                if(j>0){
                    lives += board[i][j-1];
                }
                if(j>0 && i>0){
                    lives += board[i-1][j-1];
                }
                if(j>0 && i != n-1 ){
                    lives += board[i+1][j-1];
                }
                if(i>0){
                    lives += board[i-1][j];
                }
                if(i != n-1){
                    lives += board[i+1][j];
                }
                if(j<m-1){
                    lives += board[i][j+1];
                }
                if(j<m-1 && i < n-1 ){
                    lives += board[i+1][j+1];
                }
                if(j<m-1 && i > 0 ){
                    lives += board[i-1][j+1];
                }
                if(board[i][j]){
                    if(!(lives == 2 || lives == 3)){
                        update[i][j] = 0;
                    }
                }
                else{
                    if(lives == 3){
                        update[i][j] = 1;
                    }
                }

            }
        }
        board = update;
    }
};
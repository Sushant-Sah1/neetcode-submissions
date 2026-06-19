class Solution {
public:
    bool recur(vector<vector<char>>& board, string word,int idx,int i,int j) {
        if(idx==word.size()){
            return true;
        }
        if(i<0 || i>=board.size() || j<0 || j>=board[0].size()){
            return false;
        }
        if(board[i][j]=='-'){
            return false;
        }
        if(word[idx]==board[i][j]){
            char c=board[i][j];
            board[i][j]='-';
            if(recur(board,word,idx+1,i+1,j)){
                return true;
            }
            if(recur(board,word,idx+1,i-1,j)){
                return true;
            }
            if(recur(board,word,idx+1,i,j+1)){
                return true;
            }
            if(recur(board,word,idx+1,i,j-1)){
                return true;
            }
            board[i][j]=c;
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(recur(board,word,0,i,j)){
                    return true;
                }
            }
        }
        return false;
    }
};

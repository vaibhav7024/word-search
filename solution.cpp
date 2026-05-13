class Solution {
public:
    bool solve(int curr,int i, int j,vector<vector<char>>& board, string& word){
        if(curr==word.size()) return true;
        if(i<0 || j<0 || i>=board.size()||j>=board[0].size()||board[i][j]!=word[curr]){
            return false;
        }
        char temp = board[i][j];
        board[i][j]='#';
        bool found = solve(curr+1,i+1,j,board,word)
                    ||solve(curr+1,i,j+1,board,word)
                    ||solve(curr+1,i-1,j,board,word)
                    ||solve(curr+1,i,j-1,board,word);
        bool left,right,up,down;
        board[i][j]=temp;
        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(solve(0,i,j,board,word)) return true;
            }
        }
        return false;
    }
};

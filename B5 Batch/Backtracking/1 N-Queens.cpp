class Solution {
public:
    vector<vector<string>> ans;
    
    //check validity
   bool isValid(std::vector<std::string> &nQueens, int row, int col, int &n) {
        //check if the column had a queen before.
        for (int i = 0; i != row; ++i)
            if (nQueens[i][col] == 'Q')
                return false;
        //check if the backward diagonal had a queen before.
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j)
            if (nQueens[i][j] == 'Q')
                return false;
        //check if the forward diagonal had a queen before.
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j)
            if (nQueens[i][j] == 'Q')
                return false;
        return true;
   }
    
    //main work
    void queen(int n, int row, vector<string> &board) {
        if(row == n) {
            ans.push_back(board);
            return;
        }
        
        for(int i = 0; i < n; i++){
            if(isValid(board,row,i,n)) {
                board[row][i] = 'Q';
                queen(n,row+1,board);
                board[row][i] = '.';
            }
         
        }
        return;
    }
    
    //given func
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n,string(n,'.'));
        queen(n,0,board);
        return ans;
    }
};
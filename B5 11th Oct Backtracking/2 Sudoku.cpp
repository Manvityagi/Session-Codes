class Solution
{
public:
    bool valid(vector<vector<char>> &board, int row, int col, char c)
    {
        for (int i = 0; i < 9; i++)
        {
            if (board[i][col] == c)
                return false; //check row
            if (board[row][i] == c)
                return false; //check column
           
        }
        
        int sub_matrix_i = 3 * (row / 3);
        int sub_matrix_j = 3 * (col / 3);
        
        //check 3*3 block
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if (board[sub_matrix_i + i][sub_matrix_j + j] == c)
                return false; 
            }
        }
         
        return true;
    }

    bool solve(vector<vector<char>> &board)
    {

        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.')
                {
                    for (char c = '1'; c <= '9'; c++)
                    {
                        if (valid(board, i, j, c))
                        {
                            board[i][j] = c;

                            if (solve(board))
                                return true;
                            
                            board[i][j] = '.';
                        }
                    }

                    return false;
                }
            }
        }

        return true;
    }

    void solveSudoku(vector<vector<char>> &board)
    {
        solve(board);
    }
};
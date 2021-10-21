class Solution
{
    private:
        bool isValidSub(vector<vector<char>>& board, const int x, const int y)  // Coordinate(x,y) is top left corner
        {
            unordered_set<char> check;
            
            // Get Vertical
            for (int row = x; row < x + 3; row++)
            {
                for (int col = y; col < y + 3; col++)
                {
                    if (board[row][col] != '.')
                    {
                        if(check.find(board[row][col]) != check.end()) return false;
                        check.insert(board[row][col]);
                    }
                }
            }
            
            return true;
        }
    
    public:
        bool isValidSudoku(vector<vector<char>>& board)
        {
            // Check Vertical Line
            for (int row = 0; row < 9; row++)
            {
                unordered_set<char> check;
                
                for (int col = 0; col < 9; col++)
                {
                    if (board[row][col] != '.')
                    {
                        if(check.find(board[row][col]) != check.end()) return false;
                        check.insert(board[row][col]);
                    }
                }
            }
            
            // Check Horizontal Line
            for (int col = 0; col < 9; col++)
            {
                unordered_set<char> check;
                
                for (int row = 0; row < 9; row++)
                {
                    if (board[row][col] != '.')
                    {
                        if(check.find(board[row][col]) != check.end()) return false;
                        check.insert(board[row][col]);
                    }
                }
            }
            
            // Check Sub Boxes
            for (int x = 0; x < 3; x++)
            {
                for (int y = 0; y < 3; y++)
                {
                    if (!isValidSub(board, x * 3, y * 3))
                        return false;
                }
            }
            
            return true;
        }
};  
class Solution {
    public:
    int r, c;
    void dfs(int i, int j , vector<vector<char>>& A){
        r = A.size();
        c = A[0].size();
        if(i < 0 || j < 0 || i >= r || j >= c || A[i][j] != 'O') return;
        
        A[i][j] = '1';
        dfs(i,j+1,A);
        dfs(i,j-1,A);
        dfs(i+1,j,A);
        dfs(i-1,j,A);

    }

    void solve(vector<vector<char>>& A) {
        int r = A.size();
        if(r == 0) return; 
        int c = A[0].size();
        
    
        //first row
        for(int i = 0; i < c; i++){
            if(A[0][i] == 'O'){
                //make all connected 0s 1
                dfs(0,i,A);
            }
        }
            
        //last row
        for(int i = 0; i < c; i++){
               if(A[r-1][i] == 'O'){
                //make all connected 0s 1
                dfs(r-1,i,A);
            }
        }
            
        //first col
         for(int i = 0; i < r; i++){
              if(A[i][0] == 'O'){
                //make all connected 0s 1
                dfs(i,0,A);
            }
        }
            
        //last col
         for(int i = 0; i < r; i++){
             if(A[i][c-1] == 'O'){
                //make all connected 0s 1
                dfs(i,c-1,A);
            }
        }

        //convert 0 to x
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(A[i][j] == 'O')
                    A[i][j] = 'X';
            }
        }
        
        //convert 1 to 0
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(A[i][j] == '1')
                    A[i][j] = 'O';
            }
        }
        
    }
};
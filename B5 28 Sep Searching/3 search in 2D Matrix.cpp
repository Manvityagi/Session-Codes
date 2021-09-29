//Approach 1 - This will work even if The first integer of each row is
// NOT greater than the last integer of the previous row.

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r = matrix.size();
        if(r == 0) return 0;
        int c = matrix[0].size();
        
        int i = 0, j = c-1;
        while(i < r && j >= 0){
            if(matrix[i][j] == target) return 1;
            
            if(target > matrix[i][j]) //move down
                i++;
            else   //move left
                j--;
        }
        return 0;
    }
};

//Approach 2 - log(n*m)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r = matrix.size();
        if(r == 0) return 0;
        int c = matrix[0].size();
        
       int lo = 0, hi = r*c - 1;
        
        while(lo <= hi){
            int mid = (lo+hi)/2;
            int mid_elt = matrix[mid/c][mid%c];
            
            if(target == mid_elt) return 1;
            
            if(target < mid_elt) hi = mid-1;
            else lo = mid+1;
        }
        
        return 0;
    }
};
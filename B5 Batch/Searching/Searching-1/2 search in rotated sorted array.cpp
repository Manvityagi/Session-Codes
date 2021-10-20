/*
        4, 5, 6, 7, 8, 0, 1, 2, 3 : leave maybe

        2, 3, 4, 5, 6, 7, 8, 0, 1 : target = 4, 0 

        6, 7, 8, 0, 1, 2, 3, 4, 5 : target = 8

*/

class Solution {
public:
    
    int findPivot(vector<int> arr){
        int n = arr.size(); 
        int st = 0, end = n-1,ans=0; 
        while(st <= end){
            int mid = (st+end) >> 1; 
            if(mid && arr[mid-1] > arr[mid]) return mid; 
            
            if(arr[n-1] < arr[mid]) st = mid+1;
            else end = mid-1;
            
        } 
        return 0;
    }
    
    int binarySearch(vector<int> &nums, int start, int end, int target){
        while(start <= end){
            int mid = (start + end) >> 1;
            if(nums[mid] == target){
                return mid;
            } 
            if(target > nums[mid]) start = mid+1;
            else end = mid-1;
        }
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        int n = nums.size(); 
        if(n == 1) {if(nums[0] == target) return 0; return -1;}
        if(nums[n-1] > nums[0]) return binarySearch(nums,0,n-1,target); 
        int p = findPivot(nums); 
        int op1 = binarySearch(nums, 0 , p-1, target); 
        if(op1 != -1) return op1;
        int op2 = binarySearch(nums, p, n-1, target);
        return op2;
    }
};



/*------------          APPROACH 2          -------------*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size(); 
        
        int st = 0, end = n-1; 
        
        while(st <= end){
            int mid = (st + end) >> 1;
            if(nums[mid] == target){
                return mid;
            }
            
            
            if(nums[mid] >= nums[0]){  //left half is strictly increasing
                if(target <= nums[mid] && target >= nums[st])
                    end = mid-1;
                else
                    st = mid+1;
            } else {
                
                if(target >= nums[mid] && target <= nums[end])
                    st = mid+1;
                else
                    end = mid-1;
            }
            
        }
        
        return -1;
    }
};

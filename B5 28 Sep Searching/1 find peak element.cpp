class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        int n = arr.size();
        int st = 0, end = n-1;
        while(st <= end){
            int mid = (st+end)/2; 
            if( (mid == 0 || arr[mid] > arr[mid-1]) && (mid == n-1 || arr[mid] > arr[mid+1])){
                return mid;
            }
            
            if(mid && arr[mid-1] < arr[mid]) st = mid+1;
            else if(mid && arr[mid-1] > arr[mid]) end = mid-1;
            else st = mid+1;
        }
        return -1;
    }
};
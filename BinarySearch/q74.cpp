class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(target<matrix[0][0]) return false;
        int low=0,high=matrix.size()-1;
        while(low<=high) {
            int mid = low + (high-low)/2;
            if(matrix[mid][0]==target) {
                return true;
            } else if(matrix[mid][0]>target) {
                high = mid-1;
            } else {
                low = mid+1;
            }
        }
        int row = high;
        low=0,high=matrix[row].size()-1;
        while(low<=high) {
            int mid = low + (high-low)/2;
            if(matrix[row][mid]==target) {
                return true;
            } else if(matrix[row][mid]>target) {
                high = mid-1;
            } else {
                low = mid+1;
            }
        }
        return false;
    }
};
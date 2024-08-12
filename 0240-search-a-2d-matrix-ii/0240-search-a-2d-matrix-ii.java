class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int n = matrix.length , m = matrix[0].length;
        int i = 0, j = m-1;
     
        while(i >= 0 && j >= 0 && i < n && j<m){
            int start = matrix[i][j];
            if(start > target){
                j--;
            }else if(start < target){
                i++;
            }else return true;
        }
        return false;
    }
}
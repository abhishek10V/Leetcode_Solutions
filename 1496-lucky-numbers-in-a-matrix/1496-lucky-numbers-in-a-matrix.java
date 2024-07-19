class Solution {
    public List<Integer> luckyNumbers (int[][] matrix) {
        List<Integer> list = new ArrayList<Integer>();
        for(int i=0;i<matrix.length;i++){
            int minRow = matrix[i][0];
            int find  = 0;
            for(int j=0;j<matrix[i].length;j++){
                if(minRow>matrix[i][j]){
                    minRow=matrix[i][j];
                    find = j;    
                }
            }
            int maxCol = minRow;
            Boolean ans = false;
            for(int k=0;k<matrix.length;k++){
                if(maxCol<matrix[k][find]){
                    ans=true;
                    break;
                }
            }
            
            if(ans==true){
                continue;
            }
            else{
                list.add(maxCol);
            }   
        }
        return list;
    }
}
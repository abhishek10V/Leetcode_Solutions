class Solution {
    public int numTeams(int[] rating) {
       int teams = 0;

       for(int i=1; i<rating.length - 1; i++){
            int countLeftSmaller = 0;
            int countLeftLarger = 0;
          for(int j=0; j<i; j++){
             if(rating[i] < rating[j]) countLeftLarger++;
             else if(rating[i] > rating[j]) countLeftSmaller++;
          }
           int countRightSmaller = 0;
           int countRightLarger = 0;
          for(int j=i+1; j<rating.length; j++){
           
             if(rating[i] < rating[j]) countRightLarger++;
             else if(rating[i] > rating[j]) countRightSmaller++;
          }

          teams += (countLeftLarger * countRightSmaller) + (countLeftSmaller * countRightLarger);
       }
       
       return teams; 
    }
}
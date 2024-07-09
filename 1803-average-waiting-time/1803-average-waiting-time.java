class Solution {
    public double averageWaitingTime(int[][] cust) {
        double wait = cust[0][1];
        int start = cust[0][0] + cust[0][1];
        int n = cust.length;

        for(int i=1; i<cust.length; i++){
           if(start > cust[i][0]){
              wait += start - cust[i][0] + cust[i][1];
              start += cust[i][1];
           }else{
             wait += cust[i][1];
             start = cust[i][0] + cust[i][1];
           }
        }
       
        return wait/n;
    }
}
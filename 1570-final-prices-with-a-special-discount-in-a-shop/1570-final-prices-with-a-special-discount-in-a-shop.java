class Solution {
    public int[] finalPrices(int[] prices) {
        int[] ans = prices;

        for(int i=0 ; i<prices.length - 1; i++){
            for(int j=i+1; j<prices.length; j++){
               if(prices[j] <= prices[i]){
                  ans[i] = prices[i] - prices[j];
                  break;
               }
            }
        }
      
        return ans;
    }
}
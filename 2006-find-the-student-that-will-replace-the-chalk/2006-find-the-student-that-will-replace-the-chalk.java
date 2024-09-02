class Solution {
    public int chalkReplacer(int[] chalk, int k) {
        int index = 0;
        int n = chalk.length;
        while(k > 0){
          
            if(index == n) index = 0;
            if(chalk[index] <= k){
                 k = k - chalk[index];
                 index++;
            }
            
            else if(chalk[index] > k) return index%n; 
        }
        return index%n;
    }
}
class Solution {
    public int minExtraChar(String s, String[] dictionary) {
        HashSet<String> set = new HashSet<>();
        int n = s.length();
        for(String d : dictionary) set.add(d);

        int[] dp = new int[n+1];

        for(int i=n-1 ; i>=0 ; i--){
            dp[i] = 1+dp[i+1]; //skipping the i th character 

            for(int j=i ; j<n; j++){
                String curr = s.substring(i , j + 1);
                if(set.contains(curr)) dp[i] = Math.min(dp[i] , dp[j+1]);
            }
        }

        return dp[0];
    }
}
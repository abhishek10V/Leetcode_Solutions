class Solution {
    public int maxScore(String s) {
        int maxSum = Integer.MIN_VALUE;
        int sum = 0;

        for(int i=0; i<s.length(); i++){
            if(s.charAt(i) == '1') sum++;
        }

        for(int i=0 ; i<s.length() - 1; i++){
            if(s.charAt(i) == '0') sum++;
            if(s.charAt(i) == '1') sum--;

            maxSum = Math.max(maxSum , sum);
        }
        return maxSum;
    }
}
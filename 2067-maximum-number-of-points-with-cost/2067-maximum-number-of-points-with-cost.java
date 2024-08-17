class Solution {
    public long maxPoints(int[][] p) {
        int m = p.length , n = p[0].length;

        long[] prev = new long[n];

        for(int i=0; i<n; i++) prev[i] = p[0][i];

        for(int i=1 ; i<m ; i++){
            long[] left = new long[n];
            long[] right = new long[n];

            left[0] = prev[0];
            for(int j=1; j<n; j++) left[j] = Math.max(prev[j] , left[j-1] - 1);

            right[n-1] = prev[n-1];
            for(int j=n-2; j>=0 ; j--) right[j] = Math.max(prev[j] , right[j+1] - 1);

            long[] curr = new long[n];
            for(int j=0 ; j<n; j++) curr[j] = p[i][j] + Math.max(left[j] , right[j]);

            prev = curr;
        }

        long ans = Integer.MIN_VALUE;
        for(int i=0 ; i<prev.length; i++){
           ans = Math.max(ans , prev[i]);
        }

        return ans;
    }
}
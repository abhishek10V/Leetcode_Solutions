class Solution {
    public int rangeSum(int[] nums, int n, int left, int right) {
        int[] sumArr = new int[n*(n+1)/2];
        int index = 0;
        for(int i=0; i<n; i++){
            int sum = 0;
            for(int j=i; j<n; j++){
                sum += nums[j];
                sumArr[index++] = sum;
            }
        }
        Arrays.sort(sumArr);
        int ans = 0;
        final int mod = (int) 1e9 + 7;
        for(int i=left-1 ; i<right; i++){
            ans = (ans + sumArr[i])% mod;
        }
        return ans;
    }
}
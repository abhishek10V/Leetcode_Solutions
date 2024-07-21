class Solution {
    public long minimumOperations(int[] nums, int[] target) {
    int n = nums.length;
    long operations = 0;
    int prev = 0;

    for (int i = 0; i < n; ++i) {
        int curr = nums[i] - target[i];
        if(curr > 0 && prev < 0 || curr < 0 && prev > 0){
            operations += Math.abs(curr);
        }else if(Math.abs(curr) - Math.abs(prev) > 0){
            operations += Math.abs(curr - prev);
        }

        prev = curr;
    }

    return operations;
    }
}
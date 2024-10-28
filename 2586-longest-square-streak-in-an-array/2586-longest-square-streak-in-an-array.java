class Solution {
    public int longestSquareStreak(int[] nums) {
        HashSet<Integer> set = new HashSet<>();
        Arrays.sort(nums);

        for(int i=0; i<nums.length; i++) set.add(nums[i]);
        
        int ans = 1;
        
        for(int i=0 ; i<nums.length; i++){
            int curr = 0;
            int n = nums[i];

            while(set.contains(n)){
                curr++;
             
                set.remove(n);
                n *= n;
            }
            ans = Math.max(ans , curr);
        }
      return ans == 1 ? -1 : ans;
    }
}
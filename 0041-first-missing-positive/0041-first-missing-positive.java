class Solution {
    public int firstMissingPositive(int[] nums) {
        Arrays.sort(nums);
        HashSet<Integer> set = new HashSet<>();

        for(int i=0 ; i<nums.length; i++){
            set.add(nums[i]);
        }

        for(int i=1; i<=nums[nums.length - 1]; i++){
            if(!set.contains(i)) return i;
        }
        
        return (nums[nums.length - 1] <= 0) ? 1 : nums[nums.length - 1] + 1;
    }
}
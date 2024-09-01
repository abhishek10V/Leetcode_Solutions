class Solution {
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();
        List<Integer> temp = new ArrayList<>();

        solve(0 , res, temp, nums);

        return res;
    }
    public void solve(int i ,  List<List<Integer>> res,  List<Integer> temp, int[] nums){
        if(i >= nums.length){
            res.add(new ArrayList<>(temp));
            return;
        }

        temp.add(nums[i]);
        solve(i+1, res, temp , nums);
        temp.remove(temp.size() - 1);
        solve(i+1, res, temp , nums);

    }
}
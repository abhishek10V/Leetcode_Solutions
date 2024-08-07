class Solution {
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        Arrays.sort(candidates);
        List<List<Integer>> res = new ArrayList<>();
    
        solve(res , new ArrayList<>() , candidates , target, 0);

        return res; 
    }
    public void solve(List<List<Integer>> res , List<Integer> list, int[] candidates, int target , int s){
        if(target == 0){
             res.add(new ArrayList<>(list));
             return;
        }
        if(target < 0) return;
        
        for(int i=s ; i<candidates.length; i++){
            if(i > s && candidates[i] == candidates[i-1]) continue;
            if(candidates[i] > target) break;

           
            list.add(candidates[i]);
            solve(res, list , candidates , target - candidates[i] , i+1);
            list.remove(list.size() - 1);
        }
    }
}
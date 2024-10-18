class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
      int maxOR = 0;
      for(auto & i : nums) maxOR = maxOR | i;

      int n = nums.size();

      vector<vector<int>> dp(n+1 , vector<int>(maxOR + 1 , -1));
      int currOR = 0;

      return countSub(0 , maxOR , currOR , dp , nums);
    }
    int countSub(int idx , int maxOR , int currOR , vector<vector<int>> & dp , vector<int> & nums){
        if(idx == nums.size()){
            if(currOR == maxOR) return 1;

            return 0;
        }

        if(dp[idx][currOR] != -1) return dp[idx][currOR];

        int taken = countSub(idx + 1 , maxOR , currOR | nums[idx] , dp , nums);

        int notTaken =  countSub(idx + 1 , maxOR , currOR , dp , nums);

        return dp[idx][currOR] = taken + notTaken;
    }
};
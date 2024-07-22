class Solution {
public:
    int minChanges(vector<int>& nums, int k) {
        int l = 0, r = nums.size() - 1;
        vector<int> limit;
        unordered_map<int , int> mp;
        while(l < r){
            int mn = min(nums[l] , nums[r]);
            int mx = max(nums[l] , nums[r]);
            mp[mx - mn]++;
            limit.push_back(max(mx , k - mn));
            l++ , r--;
        }

        sort(limit.begin() , limit.end());
        int sz = limit.size();
        int ans = limit.size();
        for(auto & it : mp){
            int currDiff = it.first;
            int diffCount = it.second;
            int extraOp = lower_bound(limit.begin() , limit.end() , currDiff) - limit.begin();
            extraOp += (sz - diffCount);
            ans = min(ans , extraOp);
        }
        return ans;
    }
};
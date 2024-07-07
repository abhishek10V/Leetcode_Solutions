class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
    long long ans = 0; 
        map<int , int> prev;

        for(auto &  num : nums){
            map<int , int> curr;
            for(auto & [andVal , count] : prev)
             curr[andVal & num] += count;
             curr[num]++;

             for(auto & [andVal , count] : curr){
                if(andVal == k) ans += count; 
             }

             prev = curr;
        }
        return ans;
    }
};
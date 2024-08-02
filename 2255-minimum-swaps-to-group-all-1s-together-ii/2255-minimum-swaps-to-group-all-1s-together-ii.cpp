class Solution {
public:
    int minSwaps(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        int total1s = 0;
        int ans = INT_MAX;
        for(int i=0 ; i<nums.size(); i++){
            if(nums[i] == 1) total1s++;
        }
        for(int i=0; i<total1s - 1; i++){
            nums.push_back(nums[i]);
        }
        int i=0, j=0, swap = 0;
        while(j<nums.size()){
           while(j< total1s){
            if(nums[j] == 0) swap++;
            j++;
           }
           ans = min(ans , swap);
           
           if(nums[i] == 0) swap--;
           i++;
           if(nums[j] == 0) swap++;
           j++;
           if(j - i == total1s){
             ans = min(ans , swap);
           }
        }
        
        return ans;
    }
};
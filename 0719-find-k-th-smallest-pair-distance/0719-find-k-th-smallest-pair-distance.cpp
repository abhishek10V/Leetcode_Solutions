class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int maxE = *max_element(nums.begin() , nums.end());
       vector<int> freq(maxE + 1 , 0);

       for(int i=0 ; i<nums.size() - 1; i++){
         for(int j=i+1 ; j<nums.size() ; j++){
            int d = abs(nums[j] - nums[i]);
            freq[d]++;
         }
       }
       for(int d=0 ; d<maxE+1; d++){
        k -= freq[d];
        if(k <= 0) return d;
       }
       return -1;
    }
};
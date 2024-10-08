class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
       int left = 0, right = nums.size() - 1, ans = 0;
        while(left < right){
            if(nums[left] == val && nums[right] != val){
                int temp = nums[left];
                nums[left] = nums[right];
                nums[right] = temp;
            }else if(nums[left] != val) left++;
            else if(nums[right] == val) right--;
        }
        for(int i=0 ; i<nums.size() ; i++) if(nums[i] != val) ans++;

        return ans;
    }
};
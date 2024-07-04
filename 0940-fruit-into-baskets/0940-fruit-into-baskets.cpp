class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        map<int , int> mp;
        int left = 0, right = 0, ans = 0;

        while(right < fruits.size()){
            mp[fruits[right++]]++;
            
            while(mp.size() > 2){
                int fruitCount = mp[fruits[left]];

                if(fruitCount == 1) mp.erase(fruits[left]);
                else mp[fruits[left]]--;

                left++;
            }
            ans = max(ans , right - left);
        }
        return ans;
    }
};
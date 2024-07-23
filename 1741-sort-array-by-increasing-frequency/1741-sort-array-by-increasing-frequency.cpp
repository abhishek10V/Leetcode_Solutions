class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        map<int , int> mp;
        vector<pair<int , int>> store;
        for(int i=0 ; i<nums.size(); i++){
           mp[nums[i]]++;
        }

        for(auto & it : mp){
            store.push_back({it.first , it.second});
        }

        sort(store.begin() , store.end() , [](pair<int , int>& a , pair<int , int>& b){
           if(a.second == b.second) return a.first < b.first;
           else return a.second > b.second;
        });
         nums.clear();
        for(int i=store.size() - 1 ; i>=0; i--){
            while(store[i].second > 0){
                nums.push_back(store[i].first);
                store[i].second--;
            }
        }

        return nums;
    }
};
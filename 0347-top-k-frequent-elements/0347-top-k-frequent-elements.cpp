class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int , int> freq;
        for(int & n : nums) freq[n]++;
        vector<pair<int , int>> v;
        vector<int> res;
        for(auto & it : freq){
            v.push_back({it.first , it.second});
        }
        sort(v.begin() , v.end() , [](pair<int , int>& a , pair<int , int>& b){
            return a.second > b.second;
        });

        for(int i=0 ; i<k ; i++){
            res.push_back(v[i].first);
        }
        return res;
    }
   
};
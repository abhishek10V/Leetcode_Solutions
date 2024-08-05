class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string , int> mp;
        int distinct = 0;
     
        for(string s : arr){
            mp[s]++;
        }
        for(auto & i : mp){
            if(i.second == 1) distinct++;
        }

        if(k > distinct) return "";

        for(int i=0 ; i<arr.size(); i++){
            if(mp[arr[i]] == 1) k--;
            if(k == 0) return arr[i];
        }
        return "";
    }
};
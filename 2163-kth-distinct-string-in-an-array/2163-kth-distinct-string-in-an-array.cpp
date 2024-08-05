class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string , int> mp;
        set<string> distinct;

        for(string s : arr){
            mp[s]++;
        }
        for(auto & i : mp){
            if(i.second == 1) distinct.insert(i.first);
        }
        if(k > distinct.size()) return "";
        for(int i=0 ; i<arr.size(); i++){
            if(distinct.contains(arr[i])) k--;
            if(k == 0) return arr[i];
        }
        return "";
    }
};
class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char , int> mp;

        for(auto & c : word){
            mp[c]++;
        }

    vector<pair<char, int>> vec(mp.begin(), mp.end());

    // Sort the vector based on the second value (value in the map) in descending order
    sort(vec.begin(), vec.end(), [](const pair<char, int>& a, const pair<char, int>& b) {
        return a.second > b.second;
    });

    int ans = 0;
    for(int i=0 ; i<vec.size(); i++){
        ans += (ceil((double)(i+1)/8)) * vec[i].second;
    }
    return ans;
    }
};
class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> ans;

        for(auto & q : queries){
            int currAns = 0;
            for(int i=q[0] ; i<=q[1]; i++){
               currAns ^= arr[i];
            }
            ans.push_back(currAns);
        }

        return ans;
    }
};
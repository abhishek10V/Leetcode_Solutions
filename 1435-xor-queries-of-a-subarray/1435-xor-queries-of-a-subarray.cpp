class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> ans;

        for(auto & q : queries){
            if(q[0] == q[1]){
                 ans.push_back(arr[q[0]]);
                 continue;
            }
            int currAns = 0;
            for(int i=q[0] ; i<=q[1]; i++){
               currAns ^= arr[i];
            }
            ans.push_back(currAns);
        }

        return ans;
    }
};
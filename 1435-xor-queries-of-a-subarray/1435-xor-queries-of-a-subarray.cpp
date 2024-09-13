class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> ans;
        vector<int> xorArr;
        int currXOR = 0;
        for(int i=0 ; i<arr.size(); i++){
            currXOR ^= arr[i];
            xorArr.push_back(currXOR);
        }
     
        for(auto & q : queries){
            if(q[0] == q[1]){
                ans.push_back(arr[q[0]]);
            }
            else if(q[0] == 0) ans.push_back(xorArr[q[1]]);
            else
            ans.push_back(xorArr[q[0] - 1] ^ xorArr[q[1]]);
        }
        return ans;
    }
};
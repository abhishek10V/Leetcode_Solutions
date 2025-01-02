class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& q) {
       
        unordered_set<char> vowels;
        vowels.insert('a');
        vowels.insert('e');
        vowels.insert('i');
        vowels.insert('o');
        vowels.insert('u');

        vector<int> preSum(words.size() , 0);

        if(vowels.contains(words[0][0]) && vowels.contains(words[0][words[0].size() - 1])){
            preSum[0] = 1;
        }else preSum[0] = 0;

        for(int i=1 ; i<words.size(); i++){
            if(vowels.contains(words[i][0]) && vowels.contains(words[i][words[i].size() - 1])){
                preSum[i] = preSum[i-1] + 1;
            }else preSum[i] = preSum[i-1];
        }

        vector<int> ans(q.size(), 0);
        
        for(int i=0 ; i<q.size(); i++){
            if(q[i][0] == 0) ans[i] = preSum[q[i][1]];
            else ans[i] = preSum[q[i][1]] - preSum[q[i][0] - 1];
        }
        
        return ans;
    }
 
};
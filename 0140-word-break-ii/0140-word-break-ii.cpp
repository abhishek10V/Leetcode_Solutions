class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st;
        for(string & w : wordDict) st.insert(w);
        vector<string> res;
        string currSen = "";

        solve(0 , currSen , s, res, st);

        return res;
    }
    void solve(int start , string curr , string s , vector<string>& res , unordered_set<string>& st){
        if(start >= s.length()) res.push_back(curr);

        for(int j=start ; j<s.length(); j++){
            string tempWord = s.substr(start , j-start+1);
            if(st.count(tempWord)){
                string temp = curr;
                if(!curr.empty()) curr += " ";
                curr += tempWord;
                solve(j+1 , curr , s , res, st);
                curr = temp;
            }
        }

    }
};
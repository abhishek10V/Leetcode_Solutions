class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st;
        unordered_map<string , vector<string>> mp;
        for(string & w : wordDict) st.insert(w);

        return solve(s, st, mp);
    }
    vector<string> solve(string s, unordered_set<string>& st, unordered_map<string , vector<string>>& mp){
        if(s.empty()) return {""};
        if(mp.count(s)) return mp[s];
       vector<string> res;
        for(int j=1 ; j<=s.length(); j++){
            string tempWord = s.substr(0,j);
            if(st.count(tempWord)){
                string remainWord = s.substr(j);
                vector<string> remainRes = solve(remainWord, st, mp);

                for(string & w : remainRes){
                    string toAdd = tempWord + (w.empty() ? "" : " ") + w;
                    res.push_back(toAdd);
                }
            }
        }
       return mp[s] = res;
    }
};
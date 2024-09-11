class Solution {
public:
    int minBitFlips(int start, int goal) {
       string s = bitset<32>(start).to_string();
       string g = bitset<32>(goal).to_string();
       int ans = 0;
       for(int i=0; i<s.size(); i++){
          if(s[i] != g[i]) ans++;
       }
       return ans;
    }
};
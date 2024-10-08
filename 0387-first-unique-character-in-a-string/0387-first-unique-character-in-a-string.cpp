class Solution {
public:
    int firstUniqChar(string s) {
        int freq[26];
        //fill(freq , 0);

         for(auto & ch : s){
            freq[ch - 'a']++;
        }
        for(int i=0 ; i<s.length(); i++){
            if(freq[s[i] - 'a'] == 1) return i;
        }
        return -1;
    }
};
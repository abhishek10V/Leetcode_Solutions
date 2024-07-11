class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> c(26 , 0);
        for(char ch : chars) c[ch - 'a']++;
        int res = 0;
        for(string & word : words){
            vector<int> w(26 , 0);
            for(char & ch  : word){
                w[ch - 'a']++;
            }
            bool ok = true;
            for(int i=0 ; i<26; i++){
                if(w[i] > c[i]){
                     ok = false;
                     break;
                     }
            }

            if(ok == true) res += word.size();
        }
        return res;
    }
};
class Solution {
public:
    string compressedString(string word) {
        string comp = "";
        int count = 1;
        char ch = word[0];

        for(int i=1 ; i<word.length(); i++){
          if(word[i] == ch && count < 9) count++;
          else{
              comp += to_string(count) + ch;
              ch = word[i];
              count = 1;
          }
        }
        comp += to_string(count) + ch;
        
        return comp;
    }
};
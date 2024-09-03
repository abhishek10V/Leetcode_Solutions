class Solution {
public:
    int getLucky(string s, int k) {
       string res = "";
       int ans = 0;
       for(int i=0 ; i<s.length(); i++){
           res += to_string(s[i] - 'a' + 1);
       }
       while(k > 0){
        ans = 0;
         for(int i =0 ; i<res.length(); i++){
           ans += res[i] - '0';
         }
         res = to_string(ans);
         k--;
       }
       return ans;
    }
};
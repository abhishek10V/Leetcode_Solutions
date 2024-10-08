class Solution {
public:
    int minSwaps(string s) {
        int unbalanced = 0;
        for(int i=0;i<s.size();i++){
          if(s[i]=='['){
            unbalanced+=1;
          }
          else{
            if(s[i]==']' && unbalanced>0){
              unbalanced--;
            }
          }
        }
        return (unbalanced+1)/2;
    }
};
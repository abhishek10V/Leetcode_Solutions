class Solution {
    public int maxOperations(String s) {
       boolean ok = true;
       int n = s.length();
       int zeroGroup = 0;
       int ans = 0;

       for(int i=n-1 ; i>=0 ; i--){
          if(ok && s.charAt(i) == '0'){
             zeroGroup++;
             ok = false;
          }
          if(s.charAt(i) == '1'){
            ans += zeroGroup;
            ok = true;
          }
       }
       return ans;
    }
}
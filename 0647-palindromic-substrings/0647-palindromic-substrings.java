class Solution {
    public int countSubstrings(String s) {
        int ans = 0;
        for(int i=0 ; i<s.length(); i++){
            String str;
            for(int j=i ; j<s.length(); j++){
               str = s.substring(i , j+1);
               //System.out.println(str);
               if(isPalindrome(str)) ans++;
            }
        }
        return ans;
    }
    public boolean isPalindrome(String s){
        int l = 0;
        int r = s.length() - 1;

        while(l <= r){
            if(s.charAt(l) != s.charAt(r)) return false;
            l++;
            r--;
        }
        return true;
    }
}
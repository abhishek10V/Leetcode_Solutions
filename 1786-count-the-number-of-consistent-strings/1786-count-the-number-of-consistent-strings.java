class Solution {
    public int countConsistentStrings(String allowed, String[] words) {
        HashSet<Character> a = new HashSet<>();
        int ans = 0;
        for(int i=0 ; i<allowed.length() ; i++){
            a.add(allowed.charAt(i));
        }
        for(String st : words){
            boolean flag = true;
            for(int i=0 ; i<st.length() ; i++){
               if(!a.contains(st.charAt(i))){
                   flag = false;
                   break;
               }
            }
            if(flag == true) ans++;
        }
        return ans;
    }
}
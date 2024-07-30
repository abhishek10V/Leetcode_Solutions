class Solution {
    public int minimumDeletions(String s) {
        if(s.length() == 1) return 0;
        Stack<Character> st = new Stack<>();
        int change = 0;
        for(int i=0 ; i<s.length(); i++){
            if(!st.isEmpty() && s.charAt(i) == 'a' && st.peek() == 'b'){
                st.pop();
                change++;
            }
             
            else st.push(s.charAt(i));
        }
        return change;
    }
}
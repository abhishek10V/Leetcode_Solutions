class Solution {
    public int minLength(String s) {
        Stack<Character> st = new Stack<>();

        for(int i=0 ; i<s.length() ; i++){
            if(s.charAt(i) == 'B' && !st.isEmpty()){
                if(st.peek() == 'A') st.pop();
                else st.push('B');
            }else if(s.charAt(i) == 'D' && !st.isEmpty()){
                if(st.peek() == 'C') st.pop();
                else st.push('D');
            }else st.push(s.charAt(i));
        }
        return st.size();
    }
}
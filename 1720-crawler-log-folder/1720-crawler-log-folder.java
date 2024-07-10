class Solution {
    public int minOperations(String[] logs) {
        Stack<String> st = new Stack<>();
        for(int i=0; i<logs.length; i++){
            if(logs[i].equals("../") && !st.isEmpty()){
                st.pop();
            }else if((logs[i].equals("../") && st.isEmpty()) || logs[i].equals("./")) continue;
            else {
                int in = 0;
                 StringBuilder s = new StringBuilder();
                while(logs[i].charAt(in) != '/'){
                    s.append(logs[i].charAt(in));
                    in++;
                }
               st.push(s.toString());
            }
        } 
        return st.size(); 
    }
}
class Solution {
public:
    string reverseParentheses(string s) {
        int count = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i] ==')' || s[i] == '(') count++;
        }
        
        stack<char> st;
        string ans;

       for(int i=0 ; i<s.size(); i++){
         if(s[i] == ')'){
            string sb;
            while(st.top() != '('){
                sb.push_back(st.top());
                st.pop();
            }
            st.pop();
           // if(count == 0) 

            if(st.empty() && i == s.size() - 1) ans = sb;
            else{
                for(int j=0; j<sb.size(); j++){
                   st.push(sb[j]);
                }
            }
         }else{
            st.push(s[i]);
         }
       }
       if(st.size() == 0) return ans;
       else{
        ans = "";
         while(!st.empty()){
             ans.push_back(st.top());
             st.pop();
             }
       }
       reverse(ans.begin(), ans.end());
      return ans;
    }
};
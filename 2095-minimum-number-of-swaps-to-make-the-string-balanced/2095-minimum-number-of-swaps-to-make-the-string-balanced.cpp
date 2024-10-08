class Solution {
public:
    int minSwaps(string s) {
        stack<char> st;

        for(int i=0 ; i<s.length(); i++){
            if(s[i] == ']' && !st.empty()){
                if(st.top() == '[') st.pop();
                else st.push(s[i]);
            }else st.push(s[i]);
        }
        int num = st.size()/2;

        return (num+1)/2;
    }
};
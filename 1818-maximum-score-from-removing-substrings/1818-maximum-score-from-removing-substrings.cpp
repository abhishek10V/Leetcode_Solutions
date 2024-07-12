class Solution {
public:
    int maximumGain(string s, int x, int y) {
        vector<char> st, st1;
        int points = 0;
        for(int i=0 ; i<s.size(); i++){
           if(!st.empty()){ 
            if(x >= y){
                if(s[i] == 'b' && st.back() == 'a'){
                   points += x;
                   st.pop_back();
                }else st.push_back(s[i]);
            }else{
                if(s[i] == 'a' && st.back() == 'b'){
                    points += y;
                    st.pop_back();
                }else st.push_back(s[i]);
            }
          }else st.push_back(s[i]);
        }
        for(auto a : st){
        if(!st1.empty()){ 
            if(x < y){
                if(a == 'b' && st1.back() == 'a'){
                   points += x;
                   st1.pop_back();
                }else st1.push_back(a);
            }else{
                if(a == 'a' && st1.back() == 'b'){
                    points += y;
                    st1.pop_back();
                }else st1.push_back(a);
            }
          }else st1.push_back(a);
        }
        return points;
    }
};
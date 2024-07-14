class Solution {
    public :
     string countOfAtoms(string f) {
        int n = f.size();
        stack<unordered_map<string , int>> st;
        st.push(unordered_map<string , int>());

        int i = 0;
        while(i < n){
            if(f[i] == '('){
                st.push(unordered_map<string , int>());
                i++;
            }else if(f[i] == ')'){
                unordered_map<string , int> curr = st.top();
                st.pop();

                i++;
                string mult;
                while((i<n) && isdigit(f[i])){
                    mult.push_back(f[i]);
                    i++;
                }
                if(!mult.empty()){
                    int m = stoi(mult);

                    for(auto & it : curr){
                        curr[it.first] = it.second * m;
                    }
                }

                for(auto & it : curr){
                    st.top()[it.first] += it.second;
                }
            }else {
                string currE;
                currE.push_back(f[i]);
                i++;
                while(i < n && isalpha(f[i]) && islower(f[i])){
                    currE.push_back(f[i]);
                    i++;
                }

                string currC;

                while(i<n && isdigit(f[i])){
                    currC.push_back(f[i]);
                    i++;
                }

                int currCount = currC.empty() ? 1 : stoi(currC);

                st.top()[currE] += currCount;
            }
        }

        string res;
        map<string , int> mp(st.top().begin() , st.top().end());
        
        for(auto & it : mp){
            res += it.first;
            if(it.second > 1){
                res += to_string(it.second);
            }
        }
        return res;
    }
};
class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& pos, vector<int>& h, string dir) {
        int n = pos.size();
        vector<int> res;
        vector<int> actual(n);
        stack<int> st;
        iota(actual.begin() , actual.end() , 0);

        auto lambda = [&](int & i , int & j){
           return pos[i] < pos[j];
        };
        sort(begin(actual) , end(actual), lambda);

        for(int & curr : actual){
           if(dir[curr] == 'R') st.push(curr);
           else{
             while(!st.empty() && h[curr] > 0){
             int top = st.top();
             st.pop();

             if(h[top] > h[curr]){
                h[top] -= 1;
                h[curr] = 0;
                st.push(top);
             }else if(h[top] < h[curr]){
                h[top] = 0;
                h[curr] -= 1;
             }else{
                h[top] = 0;
                h[curr] = 0;
             }
             }
           }
        }

        for(int i=0 ; i<n; i++){
            if(h[i] > 0){
                res.push_back(h[i]);
            }
        }
        return res;
    }
};
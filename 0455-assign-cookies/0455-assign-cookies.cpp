class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        if(s.size() == 0) return 0;
        sort(s.begin() , s.end());
        sort(g.begin() , g.end());
        int n = g.size() - 1;
        int ans = 0;
        while(s.size() != 0 && n >= 0 && g.size() != 0){
            if(s[s.size() - 1] >= g[n]){
                ans++;
                s.pop_back();
                g.erase(g.begin() + n);
            }else{
                n--;
            }
        }
       return ans;
    }
};
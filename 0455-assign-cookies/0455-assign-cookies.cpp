class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        if(s.size() == 0) return 0;
        sort(s.begin() , s.end());
        sort(g.begin() , g.end());
        int i = g.size() - 1, j = s.size() - 1;
        int ans = 0;
        while(i >= 0 && j >= 0){
           if(s[j] >= g[i]){
             ans++;
             i--;
             j--;
           }else i--;
        }
       return ans;
    }
};
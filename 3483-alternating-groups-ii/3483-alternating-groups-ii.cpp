class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
    int ans = 0, count = 1, n = colors.size(); 
    for(int i = 1; i < n + k-1; ++i){
        count = ( colors[i % n] != colors[(n + i - 1)%n] )? count + 1: 1;
        if(count >= k) ans++;
    }
    return ans;
    }
};
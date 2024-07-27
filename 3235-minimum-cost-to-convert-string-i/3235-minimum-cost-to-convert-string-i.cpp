class Solution {
public:
    long long minimumCost(string s, string t, vector<char>& org, vector<char>& ch, vector<int>& cost) {
        vector<vector<int>> SPM(26 , vector<int>(26 , 1e9 + 7));
        for(int i=0 ;i<26; i++) SPM[i][i] = 0;

        for(int i=0 ; i<org.size(); i++){
            SPM[org[i] - 'a'][ch[i] - 'a'] = min(cost[i] ,  SPM[org[i] - 'a'][ch[i] - 'a']);
        }
        flloydWarshall(26 , SPM);

        return findMinCost(s, t, SPM);
    }
    void flloydWarshall(int n, vector<vector<int>>& SPM){
        for(int via=0; via<n; via++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n ; j++){
                    SPM[i][j] = min(SPM[i][j] , SPM[i][via] + SPM[via][j]);
                }
            }
        }
    }
    long long findMinCost(string& s , string& t , vector<vector<int>>& SPM){
       long long ans = 0;
       for(int i=0 ; i<s.length(); i++){
        if(SPM[s[i] - 'a'][t[i] - 'a'] == 1e9+7) return -1;
        if(s[i] != t[i]) ans += SPM[s[i] - 'a'][t[i] - 'a'];
       }
       return ans;
    }
};
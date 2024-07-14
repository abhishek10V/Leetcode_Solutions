class TopVotedCandidate {
public:
     map<int, int> mp;
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        int n = persons.size();
        int currMax = persons[0];

        vector<int> votes(n,0);
        for(int i=0; i<n ; i++){
            votes[persons[i]]++;
            if(votes[persons[i]] >= votes[currMax]){
                currMax = persons[i];
            }
            mp[times[i]] = currMax;
        }
    }
    
    int q(int t) {
        auto low = mp.lower_bound(t);
        if(low->first != t) low--;
        return low->second;
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */
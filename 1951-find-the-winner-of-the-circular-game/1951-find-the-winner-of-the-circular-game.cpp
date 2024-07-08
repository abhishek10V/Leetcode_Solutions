class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> store;
        for(int i=0; i<n; i++){
            store.push_back(i+1);
        }
        int start = 0;
        while(store.size() > 1){
            store.erase(store.begin() + (start + k - 1)%store.size());
            start = (start + k - 1)%(store.size() + 1);
        }
        return store[0];
    }
};
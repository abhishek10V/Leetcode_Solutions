class Solution {
public:
    vector<int> partitionLabels(string s) {
      unordered_map<char, int> lastOccurrence;
    vector<int> res;
    
    // Step 1: Store the last occurrence of each character
    for (int i = 0; i < s.length(); i++) {
        lastOccurrence[s[i]] = i;
    }

    // Step 2: Partition the string
    int start = 0, end = 0;
    for (int i = 0; i < s.length(); i++) {
        end = max(end, lastOccurrence[s[i]]);
        if (i == end) {
            res.push_back(end - start + 1);
            start = i + 1;
        }
    }
     return res;
  }
};
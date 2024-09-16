class Solution {
public:
    int findMinDifference(vector<string>& time) {
        vector<int> minutes;

        for(int i=0 ; i<time.size() ; i++){
        int hrs = (time[i][0] - '0') * 10 + (time[i][1] - '0');
        int mins = (time[i][3] - '0') * 10 + (time[i][4] - '0');

        minutes.push_back(hrs * 60 + mins);
        }
        sort(minutes.begin() , minutes.end());
        int minDiff = INT_MAX;
        int n = minutes.size();

        if(n == 2) return min(minutes[1] - minutes[0] ,( 1440 - minutes[1]) + minutes[0]);

        for(int i = 1; i<n; i++){
            minDiff = min(minDiff , minutes[i] - minutes[i-1]);
        }
        minDiff = min(minDiff ,1440 - minutes[n-1] + minutes[0]);

        return minDiff;
    }
};
class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        sort(intervals.begin() , intervals.end());
        int grp = 1;
        priority_queue<pair<int , int> , vector<pair<int , int>> , greater<pair<int , int>>> pq;

        pq.push({intervals[0][1] , grp});

        for(int i=1; i<intervals.size(); i++){
            if(intervals[i][0] > pq.top().first){
                pq.push({intervals[i][1] , pq.top().second});
                pq.pop();
            }else{
                grp++;
                pq.push({intervals[i][1] , grp});
            }
        }
        return grp;
    }
};
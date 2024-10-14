class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<long long , vector<long long>> pq;
        for(auto & i : nums){
            pq.push(i);
        }
        long long ans = 0 ;

        while(k > 0){
            long long maxNum = pq.top();
           
            pq.pop();
            ans += maxNum;
            maxNum = ceil((maxNum + 2)/ 3);
            pq.push(maxNum);
            k--;
        }
        return ans;
    }
};
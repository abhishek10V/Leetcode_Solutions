class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int empty = 0, extra = 0;
        int ans = 0;
        while(numBottles > 0){
             cout << numBottles<<" "<< empty <<" "<< extra <<" "<< ans<<endl;

            ans += numBottles;
            empty = numBottles + extra;
            extra = empty - floor(empty/numExchange) * numExchange;
            numBottles = floor(empty/numExchange);
        }
        return ans;
    }
};
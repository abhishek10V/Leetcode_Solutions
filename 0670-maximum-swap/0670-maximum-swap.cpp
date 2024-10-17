class Solution {
public:
    int maximumSwap(int num) {
        int temp = num;
        vector<int> order;
        while(temp > 0){
           order.push_back(temp%10);
           temp = temp / 10;
        }
        reverse(order.begin() , order.end());
        vector<int> sorted = order;

        sort(sorted.begin() , sorted.end() , [](int a , int b){
            return a > b;
        });
        
        if(sorted == order) return num;
        int in1 , in2;

        for(int i=0 ; i<order.size(); i++){
            if(sorted[i] != order[i]){
               in1 = i;
               temp = sorted[i];
               break;
            }
        }
        for(int i=in1 + 1; i<order.size(); i++){
            if(order[i] == temp) in2 = i;
        }

        temp = order[in1];
        order[in1] = order[in2];
        order[in2] = temp;
        
        int ans = 0;

        for(int i=0 ; i<order.size(); i++){
            ans += order[i] * (pow(10 , order.size() - i - 1));
        }
        return ans;
    }
};
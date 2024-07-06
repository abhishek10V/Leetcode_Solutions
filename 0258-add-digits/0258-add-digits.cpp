class Solution {
public:
    int addDigits(int num) {
        if(num < 10) return num;
        int temp = num, sum = 0;
        while(temp > 0){
            sum += temp%10;
            temp = temp/10;
        }
        if(sum < 10)
        return sum;
        else return addDigits(sum);
           
    }
};
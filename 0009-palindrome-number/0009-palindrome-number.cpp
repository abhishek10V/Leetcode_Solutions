class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        long temp = x, reversed = 0, remainder;
        while(temp > 0){
            remainder = temp%10;
            reversed = reversed*10 + remainder;
            temp /= 10;
            
        }
       
        return x == (int)reversed;
    }
};
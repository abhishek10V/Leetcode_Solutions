class Solution {
public:
    int findKthNumber(int n, int k) {
        long curr = 1;
        k--;

        while(k > 0){
            int count = Count(curr , curr + 1, n);

            if(count <= k){
                curr++;
                k -= count;
            }else {
                curr *= 10;
                k--;
            }
        }
        return curr;
    }
    int Count(long curr , long next , int n){
       int counter = 0;

       while(curr <= n){
          counter += next - curr;

          curr *= 10;
          next *= 10;

          next = min(next ,long(n+1));
       }
       return counter;
    }
};
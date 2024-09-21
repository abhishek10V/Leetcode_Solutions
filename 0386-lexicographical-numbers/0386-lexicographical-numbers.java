class Solution {
    public List<Integer> lexicalOrder(int n) {
     List<Integer> res = new ArrayList<>();

     for(int i=1; i<= 9; i++){
         solve(i , n , res);

     }
     return res;
    }
    public void solve(int curr , int n , List<Integer> res){
        if(curr > n) return;

        res.add(curr);

        for(int app = 0; app<=9 ; app++){
            int newNum = curr * 10 + app;

            if(newNum > n) return;

            solve(newNum , n , res);
        }
    }
}
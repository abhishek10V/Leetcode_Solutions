class Solution {
    public int passThePillow(int n, int time) {
       int rounds = time / (n - 1);
       int k = time % (n -1);
       if(rounds%2 == 0) return k + 1;
       else return n - k;
    }
}
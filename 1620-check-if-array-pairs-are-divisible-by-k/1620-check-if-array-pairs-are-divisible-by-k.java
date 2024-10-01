class Solution {
    public boolean canArrange(int[] arr, int k) {
        int[] freq = new int[k];

        for(int n : arr){
            freq[(n%k + k)%k]++;
        }
        if(freq[0]%2 != 0) return false;

        for(int i=1  ;i<=k/2; i++){
            int half = k - i;
            if(freq[i] != freq[half]) return false;
        }
         return true;
    }
}
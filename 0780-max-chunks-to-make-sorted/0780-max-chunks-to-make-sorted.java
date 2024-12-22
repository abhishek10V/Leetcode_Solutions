class Solution {
    public int maxChunksToSorted(int[] arr) {
        int n = arr.length;
        int[] sortedArr = new int[n];
        
        for(int i=0 ; i<n; i++){
            sortedArr[i] = i;
        }
        int cummSum1 = 0;
        int cummSum2 = 0;
        int chunks = 0;
        
        for(int i=0 ; i<n ; i++){
            cummSum1 += arr[i];
            cummSum2 += sortedArr[i];

            if(cummSum1 == cummSum2) chunks++;
        }

        return chunks;
    }
}
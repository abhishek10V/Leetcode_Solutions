class Solution {
    public int minimumDeletions(String s) {
        if(s.length() == 1) return 0;
        int change = Integer.MAX_VALUE;
        int[] leftB = new int[s.length()];
        int[] rightA = new int[s.length()];
        Arrays.fill(leftB , 0);
        Arrays.fill(rightA , 0);
        int countB = 0 , countA = 0;
         for(int i=0 ; i<s.length(); i++){
            leftB[i] += countB;
            if(s.charAt(i) == 'b') countB++;
         }
          for(int i=s.length() - 1 ; i>=0; i--){
            rightA[i] += countA;
            if(s.charAt(i) == 'a') countA++;

            change = Math.min(change , rightA[i] + leftB[i]);
         }
        return change;
    }
}
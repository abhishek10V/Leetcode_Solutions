class Solution {
    public int minimumDeletions(String s) {
        if(s.length() == 1) return 0;
        int change = Integer.MAX_VALUE;
       
        int[] rightA = new int[s.length()];
        
        Arrays.fill(rightA , 0);
        int countB = 0 , countA = 0;

        for(int i=s.length() - 1 ; i>=0; i--){
            rightA[i] += countA;
            if(s.charAt(i) == 'a') countA++;
        }
        for(int i=0 ; i<s.length(); i++){
            change = Math.min(change , countB + rightA[i]);
            if(s.charAt(i) == 'b') countB++;
        }
        return change;
    }
}
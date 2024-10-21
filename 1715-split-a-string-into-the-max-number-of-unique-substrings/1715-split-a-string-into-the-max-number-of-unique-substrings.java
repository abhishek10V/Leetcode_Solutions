class Solution {
    public int maxUniqueSplit(String s) {
        return backtrack(0 , s, new HashSet<>());
    }
    public int backtrack(int start , String s , HashSet<String> seen){
        if(start == s.length()) return 0;

        int maxSplits = 0;

        for(int end = start + 1; end <= s.length() ; end++){
            String substr = s.substring(start , end);
            if(!seen.contains(substr)){
                seen.add(substr);
                maxSplits = Math.max(maxSplits ,1 + backtrack(end , s , seen));
                seen.remove(substr);
            }
        }
        return maxSplits;
    }
}
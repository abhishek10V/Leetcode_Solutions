class Solution {
    public boolean rotateString(String s, String goal) {
        return (s.length() != goal.length()) ? false : (s+s).contains(goal);
    }
}
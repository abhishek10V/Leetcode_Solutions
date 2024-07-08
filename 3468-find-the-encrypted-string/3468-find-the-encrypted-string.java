class Solution {
    public String getEncryptedString(String s, int k) {
        StringBuilder sb = new StringBuilder();
        int n = s.length();
        for(int i=0 ; i<n; i++){
            sb.append(s.charAt((i+k)%n));
        }
        return sb.toString();
    }
}
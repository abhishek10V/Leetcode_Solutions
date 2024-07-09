class Solution {
    public List<String> validStrings(int n) {
        List<String> result = new ArrayList<>();
        generate(result , new StringBuilder(), n , -1);
        return result;
    }
    public void generate(List<String> res , StringBuilder sb , int n, int lastChar){
        if(sb.length() == n){
            res.add(sb.toString());
            return;
        }

        sb.append('1');
        generate(res, sb , n, 1);
        sb.deleteCharAt(sb.length() - 1);

        if(lastChar != 0){
            sb.append('0');
            generate(res, sb , n , 0);
            sb.deleteCharAt(sb.length() - 1);
        }
    }
}
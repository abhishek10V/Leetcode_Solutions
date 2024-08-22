class Solution {
    public int findComplement(int num) {
        String binaryString = Integer.toBinaryString(num);
        StringBuilder complementString = new StringBuilder();

       
        for(int i=0 ; i<binaryString.length(); i++){
            if(binaryString.charAt(i) == '0') complementString.append('1');
            else complementString.append('0');
        }
        
        return Integer.parseInt(complementString.toString() , 2);
    }
}
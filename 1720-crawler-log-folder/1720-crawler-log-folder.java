class Solution {
    public int minOperations(String[] logs) {
        int point = 0;
        for(int i=0; i<logs.length; i++){
            if(logs[i].equals("../")){
                if(point > 0)
                point--;
            }
            else if(logs[i].equals("./"));
            else{
               point++;
            }
        } 
        return point; 
    }
}
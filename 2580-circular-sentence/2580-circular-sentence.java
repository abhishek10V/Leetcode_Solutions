class Solution {
    public boolean isCircularSentence(String sentence) {
        String[] sen = sentence.split(" ");
     
        for(int i=1; i<sen.length; i++){
            if(sen[i].charAt(0) != sen[i-1].charAt(sen[i-1].length() - 1)) return false;
        }
        
return (sen[0].charAt(0) == sen[sen.length - 1].charAt(sen[sen.length - 1].length() - 1)) ? true : false; 
    }
}
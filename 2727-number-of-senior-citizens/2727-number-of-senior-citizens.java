class Solution {
    public int countSeniors(String[] details) {
        int count = 0;
        for(int i=0 ; i<details.length; i++){
          StringBuilder sb = new StringBuilder();
          int age;
           sb.append(details[i].charAt(11));
           sb.append(details[i].charAt(12));
           age = Integer.parseInt(sb.toString());

           if(age > 60) count++;
        }
    
       return count; 
    }
}
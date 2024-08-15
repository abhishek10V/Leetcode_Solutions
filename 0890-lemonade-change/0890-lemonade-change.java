class Solution {
    public boolean lemonadeChange(int[] bills) {
        int count5 = 0, count10 = 0;

        for(int i=0 ; i<bills.length; i++){
            if(bills[i] == 10 && count5 >= 1){
                count10++;
                count5--;
            }else if(bills[i] == 20 && count10 >= 1 && count5 >= 1){
                count10--;
                count5--;
            }else if(bills[i] == 20 && count5 >= 3){
               count5 -= 3;
            }
            else if(bills[i] == 5){
                count5++;
            }else return false;
        }
        return true;
    }
}
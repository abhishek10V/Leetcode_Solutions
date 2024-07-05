/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public int[] nodesBetweenCriticalPoints(ListNode head) {
        int len = 0;
        ListNode temp = head;
        while(temp != null){
            len++;
            temp = temp.next;
        }
        int[] result = new int[2];
        result[0] = result[1] = -1;
        boolean[] cp = new boolean[len];
        if(len < 4) return result;
        int index = 1, count = 0;
        temp = head;
        head = head.next;
        while(head.next != null && index < len-1){
           if((temp.val < head.val && head.next.val < head.val) || (temp.val > head.val && head.next.val > head.val)){
              cp[index] = true;
              count++;
           }
           index++;
           head = head.next;
           temp = temp.next;
        }
        if(count < 2) return result;

        findMax(result, cp);
        findMin(result , cp, count);

        return result;
    }
    public void findMax(int[] result, boolean[] cp){
        int maxDis = 0, minDis = Integer.MAX_VALUE, left = 0, right = cp.length - 1;

        while(left < right){
            if(cp[left] == false && cp[right] == false){
                left++;
                right--;
            }else if(cp[left] == true && cp[right] == false) right--;
            else if(cp[left] == false && cp[right] == true) left++;
            else{
               maxDis = Math.max(maxDis , right - left);
               break;
            }
        }
        result[1] = maxDis;
    }
    public void findMin(int[] result , boolean[] cp, int count){
       int[] index = new int[count];
       int k=0, minDis = Integer.MAX_VALUE;
       for(int i=0 ; i<cp.length; i++){
        if(cp[i] == true) index[k++] = i;
       }
       for(int i=1; i<index.length; i++){
         minDis = Math.min(minDis , index[i] - index[i-1]);
       }
       result[0] = minDis;
    }
}
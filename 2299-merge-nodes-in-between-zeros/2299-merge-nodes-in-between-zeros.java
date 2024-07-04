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
    public ListNode mergeNodes(ListNode head) {
        ListNode result = head.next;
        ListNode curr = result;
       
    while(curr != null){
        int sum = 0;
        while(curr.val != 0){
          sum += curr.val;
          curr = curr.next;  
        } 
        
        result.val = sum;
        curr = curr.next;
        result.next = curr;
        result = result.next;;
    }
    return head.next;
  }
}
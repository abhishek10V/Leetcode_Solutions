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
    public ListNode modifiedList(int[] nums, ListNode head) {
        HashSet<Integer> set = new HashSet<>();

        for(int n : nums) set.add(n);

        while(head != null && set.contains(head.val)){
            ListNode temp = head;
            head = head.next;
        }

        ListNode curr = head;
        while(curr != null && curr.next != null){
            if(set.contains(curr.next.val)){
                ListNode temp = curr.next;
                curr.next = curr.next.next;
            }else curr = curr.next;
        }
        return head;
    }
}
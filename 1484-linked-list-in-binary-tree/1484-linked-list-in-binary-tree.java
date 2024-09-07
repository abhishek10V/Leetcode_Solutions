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
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public boolean isSubPath(ListNode head, TreeNode root) {
        if(root == null) return false;
        if(head == null) return true;

        if(root.val == head.val){
          if( dfs(root.left, head.next) || dfs(root.right , head.next)) 
        return true;
        }

       
        return  isSubPath(head , root.left) || isSubPath(head, root.right);
    }
    public boolean dfs(TreeNode node , ListNode curr){
        if(curr == null) return true;
        if(node == null) return false;

        if(node.val == curr.val) return dfs(node.left , curr.next) || dfs(node.right , curr.next);

        return false;
    }
}
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
    List<TreeNode> list = new ArrayList<>();

    public boolean isSubPath(ListNode head, TreeNode root) {
        addList(head , root);

        for(TreeNode node : list){
            if(dfs(node , head)) return true;
        }

        return false;
    }
    public void addList(ListNode head , TreeNode node){
       if(head == null || node == null) return;

       if(head.val == node.val) list.add(node);

       addList(head , node.left);
       addList(head , node.right);

    }
    public boolean dfs(TreeNode node , ListNode curr){
        if(curr == null) return true;
        if(node == null) return false;

        if(node.val == curr.val) return dfs(node.left , curr.next) || dfs(node.right , curr.next);

        return false;
    }
}
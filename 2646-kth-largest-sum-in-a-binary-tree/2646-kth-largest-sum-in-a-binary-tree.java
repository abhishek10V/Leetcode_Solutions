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
    public long kthLargestLevelSum(TreeNode root, int k) {
        PriorityQueue<Long> levelSum = new PriorityQueue<>();
        Queue<TreeNode> q = new LinkedList<>();
        q.offer(root);
        while(!q.isEmpty()){
            long sum = 0;
            int sz = q.size();

            while(sz-- > 0){
            TreeNode curr = q.poll();

            sum += curr.val;

            if(curr.left != null) q.offer(curr.left);
            if(curr.right != null) q.offer(curr.right);

            }
           
            levelSum.add(sum);

            if(levelSum.size() > k) levelSum.poll();
        }

         return levelSum.size() < k ? -1 : levelSum.peek();
    }
}
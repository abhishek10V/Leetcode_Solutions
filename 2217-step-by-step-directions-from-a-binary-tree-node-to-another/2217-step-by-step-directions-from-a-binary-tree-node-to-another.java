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
    public String getDirections(TreeNode root, int s, int d) {
        TreeNode lca = LCA(root , s , d);

        StringBuilder lcaToS = new StringBuilder();
        StringBuilder lcaToD = new StringBuilder();
        
        findPath(lca, s , lcaToS);
        findPath(lca, d , lcaToD);

        StringBuilder res = new StringBuilder();

        for(int i=0 ; i<lcaToS.length(); i++){
            res.append('U');
        }

        for(int i=0 ; i<lcaToD.length() ; i++){
            res.append(lcaToD.charAt(i));
        }

        return res.toString();
    }
    public boolean findPath(TreeNode lca , int target , StringBuilder path){
        if(lca == null) return false;
        if(lca.val == target) return true;

        path.append('L');
        if(findPath(lca.left , target , path) == true) return true;
        
        if(path.length() > 0)
        path.deleteCharAt(path.length() - 1);

         path.append('R');
        if(findPath(lca.right , target , path) == true) return true;

        if(path.length() > 0)
        path.deleteCharAt(path.length() - 1);

        return false;
    }
    public TreeNode LCA(TreeNode root, int s, int d){
        if(root == null) return null;

        if(root.val == s || root.val == d) return root;

        TreeNode left = LCA(root.left , s , d);
        TreeNode right = LCA(root.right , s , d);
        
        if(left == null) return right;
        if(right == null) return left;

        return root;
    }
}
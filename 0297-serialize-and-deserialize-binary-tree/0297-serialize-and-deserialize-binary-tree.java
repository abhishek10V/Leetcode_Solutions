/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Codec {
    
    // Encodes a tree to a single string.
    public String serialize(TreeNode root) {
       if(root == null) return "";
       Queue<TreeNode> q = new LinkedList<>();
       StringBuilder sb = new StringBuilder();

       q.add(root);

       while(!q.isEmpty()){
        TreeNode node = q.poll();
        if(node == null){
             sb.append("#,");
             continue;
        }
         sb.append(node.val + ",");
         q.add(node.left);
         q.add(node.right);
       }

       return sb.toString();
    }
    
    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
      if(data.length() == 0) return null;
      Queue<TreeNode> q = new LinkedList<>();
      String[] s = data.split(",");
      TreeNode root = new TreeNode(Integer.parseInt(s[0]));
      q.add(root);
      
      for(int i=1 ; i<s.length; i++){
        TreeNode parent = q.poll();
        if(!s[i].equals("#")){
            TreeNode left = new TreeNode(Integer.parseInt(s[i]));
            parent.left = left;
            q.add(left);
        }
         if(!s[++i].equals("#")){
            TreeNode right = new TreeNode(Integer.parseInt(s[i]));
            parent.right = right;
            q.add(right);
        }
      }
      return root;
    }
}

// Your Codec object will be instantiated and called as such:
// Codec ser = new Codec();
// Codec deser = new Codec();
// TreeNode ans = deser.deserialize(ser.serialize(root));
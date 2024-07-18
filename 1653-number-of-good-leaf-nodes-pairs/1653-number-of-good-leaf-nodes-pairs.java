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
    public void makeGraph(TreeNode root, TreeNode prev, Map<TreeNode, List<TreeNode>> adj, Set<TreeNode> leafNodes) {
        if (root == null) {
            return;
        }

        if (root.left == null && root.right == null) { // Leaf node
            leafNodes.add(root);
        }

        if (prev != null) {
            adj.computeIfAbsent(root, k -> new ArrayList<>()).add(prev);
            adj.computeIfAbsent(prev, k -> new ArrayList<>()).add(root);
        }

        makeGraph(root.left, root, adj, leafNodes);
        makeGraph(root.right, root, adj, leafNodes);
    }

    public int countPairs(TreeNode root, int distance) {
        Map<TreeNode, List<TreeNode>> adj = new HashMap<>(); // Graph
        Set<TreeNode> leafNodes = new HashSet<>(); // Leaf nodes

        makeGraph(root, null, adj, leafNodes);

        int count = 0; // Count of good node pairs

        for (TreeNode leaf : leafNodes) {
            // Perform BFS and see if you can find other leaf nodes within distance
            Queue<TreeNode> queue = new LinkedList<>();
            Set<TreeNode> visited = new HashSet<>();
            queue.add(leaf);
            visited.add(leaf);

            for (int level = 0; level <= distance; level++) { // Only go till level <= distance
                int size = queue.size();
                while (size-- > 0) { // Process level
                    TreeNode curr = queue.poll();

                    if (curr != leaf && leafNodes.contains(curr)) {
                        count++;
                    }

                    for (TreeNode neighbor : adj.getOrDefault(curr, new ArrayList<>())) {
                        if (!visited.contains(neighbor)) {
                            queue.add(neighbor);
                            visited.add(neighbor);
                        }
                    }
                }
            }
        }
        return count / 2;
    }
}
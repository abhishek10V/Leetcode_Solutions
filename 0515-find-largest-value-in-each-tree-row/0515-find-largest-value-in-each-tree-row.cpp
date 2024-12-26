/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if(root == NULL) return {};
        queue<TreeNode *> q;
        q.push(root);
        vector<int> res;

        for(int level = 0; !q.empty(); level++){
            int sz = q.size();
            res.push_back(INT_MIN);
            
            while(sz-- > 0){
            TreeNode * curr = q.front();
            q.pop();
            res[level] = max(res[level] , curr->val);

            if(curr->right != NULL) q.push(curr->right);
            if(curr->left != NULL) q.push(curr->left);
            }
        }
        return res;
    }
};
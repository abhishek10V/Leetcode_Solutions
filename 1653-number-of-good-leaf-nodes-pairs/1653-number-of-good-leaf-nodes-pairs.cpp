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
    void makeGraph(TreeNode * node , TreeNode * prev ,  unordered_map<TreeNode * , vector<TreeNode *>>& mp, unordered_set<TreeNode *>& st){
        if(node == NULL) return;

        if(node->left == NULL && node->right == NULL) st.insert(node);

        if(prev != NULL){
            mp[node].push_back(prev);
            mp[prev].push_back(node);
        }

        makeGraph(node->left , node , mp , st);
        makeGraph(node->right , node , mp , st);
    }

    int countPairs(TreeNode* root, int distance) {
        unordered_map<TreeNode * , vector<TreeNode *>> mp;
        unordered_set<TreeNode *> st;
        
        makeGraph(root , NULL , mp , st);
        int count = 0;
        for(auto & leaf : st){
            queue<TreeNode *> q;
            unordered_set<TreeNode *> vis;
            q.push(leaf);
            vis.insert(leaf);
            
            for(int lev = 0; lev <= distance ; lev++){
                int sz = q.size();
                while(sz-- > 0){
                    TreeNode * curr = q.front();
                    q.pop();

                    if(curr != leaf && st.count(curr)) count++;

                    for(auto & ngbr : mp[curr]){
                        if(!vis.count(ngbr)){
                           q.push(ngbr);
                           vis.insert(ngbr);
                        }
                    }
                }
            }
        }
       return count/2;
    };
};
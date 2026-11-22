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
   private:
    // return the number of the good nodes it takes the current node and the max
    int dfs(TreeNode* node, int max1) {
        if (node == nullptr) {
            
            return 0;
        }
      

        int res = (node->val>=max1)?1:0;
        max1=max(max1,node->val);
        res+=dfs(node->left,max1);
    
        res+=dfs(node->right,max1);
        
        return res;}

   public:
    int goodNodes(TreeNode* root) {
        if (root==nullptr) return 0;
        int count = dfs(root, root->val);
        return count;
    }
};

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==nullptr)
        return root;
        if(root==p || root==q)
        return root;
        //now i need to abuse the property of bst 
        //first i will search in subtree if both are there in the subtree then the current node is lca and if only one is present on the subtree we need go up
        //nad check on right tree till we get subtree in both of them;
        if(p->val<root->val && q->val<root->val)
         return lowestCommonAncestor(root->left,p,q);
         else if(p->val>root->val && q->val>root->val)
       return lowestCommonAncestor(root->right,p,q);
        
        else return root;    
   return root; }
};

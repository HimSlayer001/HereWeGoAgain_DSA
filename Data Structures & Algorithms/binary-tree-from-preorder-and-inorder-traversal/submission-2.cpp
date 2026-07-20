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
TreeNode* dfs(unordered_map<int,int>&inMAP,vector<int>& preorder, vector<int>& inorder,int InStart,int InEnd,int preStart,int preEnd)
    {   if(preStart>preEnd || InStart>InEnd) return nullptr;
        
        
        TreeNode* root=new TreeNode(preorder[preStart]);
      int index=inMAP[root->val];
        int numsleft=index-InStart;

        root->left=dfs(inMAP,preorder,inorder,InStart,index-1,preStart+1,preStart+numsleft);
        root->right=dfs(inMAP,preorder,inorder,index+1,InEnd,preStart+numsleft+1,preEnd);
  return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
      int n=preorder.size();
      
      unordered_map<int,int>inMAP;
      for(int i=0; i<n; ++i)
      {
        inMAP[inorder[i]]=i;
      }
           return dfs(inMAP,preorder,inorder,0,inorder.size()-1,0,preorder.size()-1);
                }
};

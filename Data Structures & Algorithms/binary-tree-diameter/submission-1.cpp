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
int dfs(TreeNode* node,int& res) 
{
if(node==nullptr)
return 0;

//i want to go left

    int left=dfs(node->left,res);

    int right=dfs(node->right,res);
    res=max(res,left+right);
    return 1+max(left,right);
}
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
    if(root==nullptr)
    {
    return 0;
    }

//what i will send is -> take the lpngest path from both side and check which is greatee and add 1 and send that information above
//can use dfs 
//go down return when nothing
int res=0;
dfs(root,res);
return res;

    }
};

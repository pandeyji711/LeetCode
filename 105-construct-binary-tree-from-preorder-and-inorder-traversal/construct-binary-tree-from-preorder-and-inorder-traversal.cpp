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
  
   TreeNode* build( unordered_map<int,int>&m,vector<int>&inor,vector<int>& preorder,int &ind ,int l ,int r )
   {
                   if(ind>=preorder.size()) return nullptr;
                      if(l>r)return nullptr;


                     TreeNode* root=new   TreeNode(preorder[ind]);
                     int index=m[preorder[ind]];
                     ind++;
                     root->left=build(m,inor,preorder,ind,l,index-1);
                      root->right=build(m,inor,preorder,ind,index+1,r);
                      return root;
   }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>m;
        for(int i=0;i<inorder.size();i++)
        {
                m[inorder[i]]=i;
        }

        int ind=0;
        return build(m,inorder,preorder,ind,0,preorder.size()-1);
    }
};
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
  
   
    vector<int> rightSideView(TreeNode* root) {
        if(root==nullptr)
        return {};
         vector<vector<int>>mat;
         queue<TreeNode*>q;
         q.push(root);
         mat.push_back({root->val});
        //  ind=1;
         while(!q.empty())
         {
               int n=q.size();
               vector<int>tem;
               for(int i=0;i<n;i++)
               {
                    TreeNode* node=q.front();
                    q.pop();
                      if(node->left!=nullptr)
                      {
                             q.push(node->left);
                             tem.push_back(node->left->val);
                      }
                       if(node->right!=nullptr)
                      {
                             q.push(node->right);
                             tem.push_back(node->right->val);
                      }
               }
               if(tem.size()>0)
               mat.push_back(tem);
         }
         vector<int>ans;
         for(int i=0;i<mat.size();i++)
         {
                 ans.push_back(mat[i][mat[i].size()-1]);
         }
         return ans;
    }
};
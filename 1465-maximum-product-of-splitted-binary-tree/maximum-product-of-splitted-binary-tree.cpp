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
    int sumofallnodes(TreeNode* root)
    {
             if(!root)return 0;
             if(root->left==nullptr&&root->right==nullptr)
             {
                  return root->val;
             }
             int left=sumofallnodes(root->left);
             int right=sumofallnodes(root->right);
             return root->val+left+right;
    }
    long total=0;
    long long ans=0;
    int mod=1e9+7;
      int sumofallnodes1(TreeNode* root)
    {
             if(!root)return 0;
            //  if(root->left==nullptr&&root->right==nullptr)
            //  {
            //       return root->val;
            //  }
             int left=sumofallnodes1(root->left);
             int right=sumofallnodes1(root->right);
             ans=(max(ans,(long long)((total-root->val-left-right)*(root->val+left+right))));
             return root->val+left+right;
    }
    int maxProduct(TreeNode* root) {
    total= sumofallnodes(root);
   
        sumofallnodes1(root);
        return ans%mod;
    }
};
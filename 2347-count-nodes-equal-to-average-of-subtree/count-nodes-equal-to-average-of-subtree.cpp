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
   int sum(TreeNode* root,int &cnt)
   {
         if(root==NULL)return 0;
         cnt++;
         return root->val+sum(root->left,cnt)+sum(root->right,cnt);
   }
   int avg(TreeNode* root)
   {
         if(root==NULL)return 0;
           int val=root->val;
               int cnt=0;
               int s=sum(root,cnt);
               int a=0;
               if(val==s/cnt)
               a=1;
         return a+avg(root->left)+avg(root->right);
   }
    int averageOfSubtree(TreeNode* root) {
        
        return avg(root);
    }
};
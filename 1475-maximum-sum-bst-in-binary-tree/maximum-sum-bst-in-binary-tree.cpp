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
  int ans=0;
  vector<int> solve(TreeNode* root)
   {
             if(!root)
             return {1,0,INT_MAX,INT_MIN};

             auto a=solve(root->left);
             auto b=solve(root->right);
              int minn=min({a[2],b[2],root->val});
                int maxx=max({a[3],b[3],root->val});
             if(a[0]&&b[0]&&(root->val>a[3]&&root->val<b[2]))
             {
                 
                  
                      ans=max(ans,root->val+a[1]+b[1]);
                    
                        return {1,root->val+a[1]+b[1],minn,maxx};
                
             }
             return {0,root->val+a[1]+b[1],maxx,minn};
   }
    int maxSumBST(TreeNode* root) {
        solve(root);
       
        return ans;
    }
};
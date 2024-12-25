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
    vector<int> largestValues(TreeNode* root) {
        vector<int>ans;
        queue<TreeNode*>q;
        q.push(root);
        if(root==nullptr)
        return {};
        ans.push_back(root->val);
        while(!q.empty())
        {
              int n=q.size();
              int maxx=INT_MIN;
              for( int i=0;i<n;i++)
              {
                   TreeNode* node=q.front();
                   if(node->left){
                    q.push(node->left);
                    maxx=max(maxx,node->left->val);
                   }
                    if(node->right){
                    q.push(node->right);
                    maxx=max(maxx,node->right->val);
                   }
                   q.pop();
              }
              if(!q.empty())
              ans.push_back(maxx);
        }
        return ans;
    }
};
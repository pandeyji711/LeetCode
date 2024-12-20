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
    void reverse_odd(vector<TreeNode*>&v)
    {
            vector<int>num;
            for( int i=0;i<v.size();i++)
            {
                   num.push_back(v[i]->val);
                   
            }
              reverse(num.begin(),num.end());
              for( int i=0;i<v.size();i++)
            {
                //  cout<<num[i]<<" ";
                   v[i]->val=num[i];
                   
            }
            // return;
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        
                if (!root) return nullptr;
             queue<TreeNode*>q;
             q.push(root);
             int h=1;
             while(!q.empty())
             {
                  int n=q.size();
                  vector<TreeNode*>v;
                  for(int i=0;i<n;i++)
                  {
                       TreeNode* node = q.front();
                        q.pop();
                         if(node->left!=nullptr)
                         {
                             q.push(node->left);
                             v.push_back(node->left);
                         }
                          if(node->left!=nullptr)
                         {
                             q.push(node->right);
                               v.push_back(node->right);
                         }
                         
                  }
                  
                  if(h%2!=0){
                  reverse_odd(v);
                //   cout<<"l";
                  }
                  h++;
                  
                    
             }
             return root;
    }
};
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
    // vector<TreeNode*>ans;
     map<pair<int,int>,vector<TreeNode*>>dp;
     vector<TreeNode*> solve(int n,int str,int end)
    {
                 vector<TreeNode*> result;
        if (str > end) {
            result.push_back(nullptr);  // Empty tree
            return dp[{str,end}]= result;
        }
        if(dp.find({str,end})!=dp.end())
        return dp[{str,end}];
                
                 for(int k=str;k<=end;k++){
                  vector<TreeNode*>left=solve(n,str,k-1);
                    vector<TreeNode*>right=solve(n,k+1,end);
                    for(int i=0;i<left.size();i++)
                    {
                         for(int j=0;j<right.size();j++)
                         {
                                TreeNode* newroot= new  TreeNode(k);
                                newroot->left=left[i];
                                newroot->right=right[j];
                                result.push_back(newroot);
                         }
                    }
    

                 }
                 return dp[{str,end}]=result;
    }
    vector<TreeNode*> generateTrees(int n) {
    
       

     
    //    cout<<root->val;
        // solve(n-1,root,nullptr);
        return solve(n,1,n);
    }
};
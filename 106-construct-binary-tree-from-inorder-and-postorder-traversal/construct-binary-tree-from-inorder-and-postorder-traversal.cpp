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
unordered_map<int,int>m;
    TreeNode*  build(vector<int>& inorder, vector<int>& postorder,int &ind ,int l,int r)
    {
           if(ind<0||l>r)return nullptr;

         TreeNode* root = new  TreeNode(postorder[ind]);
        
         int index=m[postorder[ind]];
          ind--;
            root->right=build(inorder,postorder,ind,index+1,r);
            root->left=build(inorder,postorder,ind,l,index-1);
       
         return root;


    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // unordered_map<int,int>m;
        for(int i=0;i<inorder.size();i++)
        {
                m[inorder[i]]=i;
        }
        int ind=inorder.size()-1;
        return build(inorder,postorder,ind,0,ind);

    }
};
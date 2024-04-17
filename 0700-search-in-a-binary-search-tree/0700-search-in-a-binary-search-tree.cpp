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
    TreeNode * temp =  new TreeNode(0) ;
   void search(TreeNode* root , int val) 
   {
       if(!root) return  ;
       if(root->val == val )  {
           temp = root ;
           return ;
       }
       else if( root->val < val) {
           search(root->right , val ) ;
       }
       else {
           search(root->left  , val) ;
       }
       
   }
    TreeNode* searchBST(TreeNode* root, int val) {
        search(root , val) ;
        if(temp->val == 0) return nullptr;
        return  temp ;
    }
};
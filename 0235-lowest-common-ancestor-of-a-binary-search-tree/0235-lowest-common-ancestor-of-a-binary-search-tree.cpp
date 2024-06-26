class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
     if(!root || root == p || root == q ) return root ;
     auto left = lowestCommonAncestor(root->left , p , q) ;
     auto right = lowestCommonAncestor(root->right , p , q) ;
       if( left== NULL) return right;
         else if (right ==  NULL) return left ; 
         else return root;  
    }
};

class Solution {
public:
    
     TreeNode * rightmost (TreeNode * root){
         while(root->right!= nullptr) {
             root= root->right ;
         }
         return root ;
     }
    TreeNode* deleteNode(TreeNode* root, int key) {
                if(!root) return nullptr; 
            if( root->val == key ) {
             //  0 children
             if( !root->left && !root->right){
                 auto x = root ;
                 delete x ;
                 return nullptr ;
             }
               if( !root->left && root->right){
                 auto temp = root->right ;
                  auto x  = root ; 
                 delete x ;
                 return temp ;
             }
               if( root->left && !root->right){
                 auto temp = root->left ;
                  auto x  = root ; 
                 delete x ;
                 return temp ;
             }
             if( root->left && root->right){
                 auto x =  root ;
                 auto tempr  = root->right ;
                 auto templ = root->left;
                 auto rightm =  rightmost(templ) ;
                 rightm->right =  tempr ;
                 delete x ;
                 return templ ;
             }
            }
        else if( root->val  > key) {
            root->left  = deleteNode(root->left , key ) ;
            
        }
        else {
             root->right = deleteNode(root->right , key) ;
            
        }
        return root ;
    }
};
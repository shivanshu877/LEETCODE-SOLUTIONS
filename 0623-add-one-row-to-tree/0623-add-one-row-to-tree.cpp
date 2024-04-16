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
//     int f (TreeNode* root) {
//         if(!root)return 0 ;
//         int l = f(root->left) ;
//         int r = f(root->right);
        
//         return max(l , r ) + 1  ;
//     }
    
    
    TreeNode* addOneRow(TreeNode* root, int v, int depth) {
       queue<TreeNode*>  ans ;
       ans.push(root) ;
       int cnt = 1 ;
      if(depth ==  1) {
        auto temp = root ; 
       auto x = new TreeNode(v);
       x->left = temp ;
       return x ;
      }
        while(!ans.empty()){
             if(cnt == depth - 1 ){
            cout << cnt ;
        break ;
        }  
       int t =  ans.size() ;
        for(int i = 0 ; i < t ;i++) {
        auto x = ans.front() ;
        ans.pop() ;
            if(x->left)ans.push(x->left) ;
            if(x->right)ans.push(x->right) ;
        }
        cnt++ ; 
         
       } 
       cout<< endl ;
       while(!ans.empty()) {
       auto temp = ans.front() ; 
       cout << temp->val  <<" "; 
       auto l =  temp->left ;
       auto r = temp->right ;
       auto x = new TreeNode(v);
       auto y = new TreeNode(v);
       temp->left = x ;
       temp->right = y ;
       if(l) x->left = l;
       if(r) y->right = r ;

       ans.pop() ;
       }
       return root;
        
    }
};
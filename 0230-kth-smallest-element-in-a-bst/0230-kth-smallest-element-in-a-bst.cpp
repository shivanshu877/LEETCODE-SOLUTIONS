
class Solution {
public:
    int x = 0  ;
    int temp = 0;
    void f(TreeNode * root ,int k ) {
        if(!root) return ;
        f(root->left ,  k) ;
        x++;
        if(k == x ) { temp = root->val  ;
                    return ;
                    }f(root->right , k) ;
    }
    int kthSmallest(TreeNode* root, int k) {
        f(root , k) ;
        return temp ;
    }
};
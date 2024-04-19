class Solution {
    vector<int> v{};
    void inorder(TreeNode* root)
    {
        if(root != NULL)
        {
            inorder(root->left);
            v.push_back(root->val);
            inorder(root->right);
        }
    }
    void check(TreeNode* root)
    {
        if(root != NULL)
        {
            check(root->left);
            if(root->val != v.front())
            {
                root->val = v.front();
            }
            v.erase(v.begin());
            check(root->right);
        }
    }
public:
    void recoverTree(TreeNode* root) {
       inorder(root);
       sort(v.begin(), v.end() );
       check(root);

    }
};
class Solution {
    public:
    int minDepth(TreeNode* root) {
        if(root==NULL) return 0;
        int left=1,right=1;
        if(root->left) left=1+minDepth(root->left);
        if(root->right) right=1+minDepth(root->right);

        if(left==1) return right;
        if(right==1) return left;

        return min(left,right);
    }
};
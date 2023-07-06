class Solution {
public:

    int LevelOrder(TreeNode* root) {
         vector<int> arr;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            auto front=q.front();
            arr.push_back(front->val);
            q.pop();

            if(front->left) q.push(front->left);
            if(front->right) q.push(front->right);
        }
        int ans=1e9;

        sort(arr.begin(),arr.end());

        for(int i=1;i<arr.size();i++) {
            ans=min(ans,arr[i]-arr[i-1]);
        }

        return ans;
    }

    void inorder(TreeNode* root,vector<int> &in) {
        if(root==NULL) return ;

        inorder(root->left,in);
        in.push_back(root->val);
        inorder(root->right,in);
    }

    TreeNode* prev=NULL;

     void inorderOpt(TreeNode* root,int &ans) {
        if(root==NULL) return ;

        inorderOpt(root->left,ans);
        if(prev) ans=min(ans,root->val - prev->val);
        
        prev=root;
        inorderOpt(root->right,ans);
        
    }
    int getMinimumDifference(TreeNode* root) {
        // by levelOrder
    //    return LevelOrder(root);
    
    //inorder with list
        // vector<int> in;

        // int mini=1e9;
        // inorder(root,in);
        // int n=in.size();

        // for(int i=1;i<n;i++) {
        //     mini=min(mini,in[i]-in[i-1]);
        // }
        // return mini;

        //inorder without list
        int ans=1e9;
        bool path=0;
        inorderOpt(root,ans);
        return ans;
    }
};
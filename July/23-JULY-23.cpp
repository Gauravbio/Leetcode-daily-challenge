class Solution {
    unordered_map<int,vector<TreeNode*>> dp;
public:
    vector<TreeNode*> allPossibleFBT(int n) {
        if(n%2==0) return {};

        if(n==1) {
            return {new TreeNode(0)};
        }
        
        if(dp.count(n)) return dp[n];

        vector<TreeNode*> ans;

        for(int i=1;i<n;i+=2){
            vector<TreeNode*> left=allPossibleFBT(i);
            vector<TreeNode*>right=allPossibleFBT(n-i-1);

            for(auto l: left) {
                for(auto r:right) {
                    TreeNode* node=new TreeNode(0,l,r);
                    ans.push_back(node);
                }
            }
        }

        dp[n]=ans;
        return ans;
    }
};
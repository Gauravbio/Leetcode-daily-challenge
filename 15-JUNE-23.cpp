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
    private:
    int bfs(TreeNode* root) {
        queue<pair<TreeNode*,int>> q;
        unordered_map<int,int> mp;
        q.push({root,1});

        while(!q.empty()) {
            TreeNode* front=q.front().first;
            int lvl=q.front().second;
            q.pop();
            mp[lvl]+=front->val;

            if(front->left) q.push({front->left,lvl+1});
            if(front->right) q.push({front->right,lvl+1});
        }

        int maxi=-1e9,ans=0;

        for(auto it: mp) {
            if(it.first<ans && maxi==it.second) {
                ans=it.first;
            }
            else if(maxi<it.second) {
                maxi=it.second;
                ans=it.first;
            }

            // cout<<it.first<<" "<<it.second<<endl;
        }

        return ans;
    }

    int optimisedBfs(TreeNode* root) {
        queue<pair<TreeNode*,int>> q;
        q.push({root,1});
        int prevLvl=0;
        int ans=1;
        int sum=root->val;
        int currSum=-1e9;
        int currLvl=1;

        while(!q.empty()) {
            TreeNode* front=q.front().first;
            currLvl=q.front().second;
            q.pop();
            if(currLvl!=prevLvl) {
                if(sum<currSum) {
                    sum=currSum;
                    ans=prevLvl;
                }
                prevLvl=currLvl;
                currSum=0;
            }
            currSum+=front->val;
            if(front->left) q.push({front->left,currLvl+1});
            if(front->right) q.push({front->right,currLvl+1});
        }

        if(sum<currSum) {
            ans=currLvl;
        }
        return ans;
    }
public:
    int maxLevelSum(TreeNode* root) {
        // return bfs(root);
        return optimisedBfs(root);
    }
};
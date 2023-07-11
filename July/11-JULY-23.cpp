/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    private:
    int parentBnaDo(TreeNode* root,unordered_map<TreeNode*,TreeNode*> &parent) {
        queue<TreeNode*> q;
        q.push(root);
        int maxi=0;

        while(!q.empty()) {
            TreeNode* node=q.front();
            q.pop();
            maxi=max(node->val,maxi);
            if(node->left) {
                parent[node->left]=node;
                q.push(node->left);
            }
            if(node->right) {
                parent[node->right]=node;
                q.push(node->right);
            }
        }

        return maxi;
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(root==NULL) return {};
        unordered_map<TreeNode*,TreeNode*> map;
        map[root]=NULL;
        int maxi=parentBnaDo(root,map);

        queue<pair<TreeNode*,int>> q;
        q.push({target,0});
        vector<bool> vis(maxi+1,0);
        vis[target->val]=1;

        while(!q.empty()) {
            TreeNode* node=q.front().first;
            int dist=q.front().second;
            if(dist==k) break;
            q.pop();

            if(node->left && !vis[node->left->val]) {
                q.push({node->left,dist+1});
                vis[node->left->val]=1;
            }
            if(node->right && !vis[node->right->val]) {
                q.push({node->right,dist+1});
                vis[node->right->val]=1;
            }
            if(map[node] != NULL && !vis[map[node]->val]) {
                q.push({map[node],dist+1});
                vis[map[node]->val]=1;
            }
        }

        vector<int> ans;
        while(!q.empty()) {
            int node=q.front().first->val;
            ans.push_back(node);
            q.pop();
        }

        return ans;
    }
};
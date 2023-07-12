class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<bool> vis(n,0);
        vector<int> adj[n];
        vector<int> inDegree(n,0);

        for(int i=0;i<n;i++) {
            for(auto node: graph[i]) {
                adj[node].push_back(i);
                inDegree[i]++;
            }
        }

        queue<int> q;
        for(int i=0;i<n;i++) {
            if(inDegree[i]==0) q.push(i);
        }
        vector<int> ans;
        while(!q.empty()){
            int front=q.front();
            ans.push_back(front);
            q.pop();

            for(auto node: adj[front]){
                inDegree[node]--;
                if(inDegree[node]==0) q.push(node);
            }
        }

        sort(ans.begin(),ans.end());
        return ans;
    }
};
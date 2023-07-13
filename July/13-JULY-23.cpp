class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        int n=prerequisites.size();
        vector<int> inDegree(numCourses,0);

        // making adjacency list
        for(int i=0;i<n;i++) {
            int u=prerequisites[i][0];
            int v=prerequisites[i][1];

            inDegree[u]++;
            adj[v].push_back(u);
        }

        queue<int> q;
        vector<bool> vis(numCourses,0);
        for(int i=0;i<numCourses;i++) {
            if(inDegree[i]==0) {
                q.push(i);
                vis[i]=1;    
            }
        }

        int course=0;
        // bfs
        while(!q.empty()) {
            int front=q.front();
            course++;
            q.pop();

            for(auto it: adj[front]) {
                inDegree[it]--;
                if(!vis[it] && inDegree[it]==0) {
                    q.push(it);
                    vis[it]=1;
                }
            }
        }

        return course==numCourses;
    }
};
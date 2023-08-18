class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> rank(n,0);
        map<pair<int,int>,bool> mp;

        for(auto road: roads) {
            int u=road[0];
            int v=road[1];
            mp[{u,v}]=1;
            mp[{v,u}]=1;

            rank[u]++;
            rank[v]++;
        }

        int ans=0;
        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                if(mp.count({i,j})) {
                    ans=max(ans,rank[i]+rank[j]-1);
                }
                else ans=max(ans,rank[i]+rank[j]);
            }
        }
        
        return ans;
    }
};
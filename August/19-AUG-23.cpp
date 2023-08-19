class DSU {
    vector<int> rank,parent;

    public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n,0);

        for(int i=0;i<n;i++) {
            parent[i]=i;
        }
    }

    int find_parent(int u) {
        if(parent[u]==u) return u;
        return parent[u]=find_parent(parent[u]);
    }

    void union_by_rank(int u,int v) {
        int u_p=find_parent(u);
        int v_p=find_parent(v);

        if(u_p == v_p) return ;
        else if(rank[u_p]>rank[v_p]) {
            parent[v_p]=u_p;
        }
        else if(rank[u_p]<rank[v_p]) {
            parent[u_p]=v_p;
        }
        else {
            parent[u_p]=v_p;
            rank[v_p]++;
        }
    }
};

class Solution {

    int getMST(vector<vector<int>>& edges,int n,int includeEdge=-1,int excludeEdge=-1) {
        DSU dsu(n);
        int weight=0;

        if(includeEdge!=-1) {
            dsu.union_by_rank(edges[includeEdge][0],edges[includeEdge][1]);
            weight+=edges[includeEdge][2];
        }

        for(int i=0;i<edges.size();i++) {
            if(i==excludeEdge) continue;
            int u=edges[i][0];
            int v=edges[i][1];

            if(dsu.find_parent(u)!=dsu.find_parent(v)) {
                dsu.union_by_rank(u,v);
                weight+=edges[i][2];
            }
        }

        for(int i=0;i<n;i++) {
            if(dsu.find_parent(i)!=dsu.find_parent(0)) return 1e9;
        }

        return weight;
    }

public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        for(int i=0;i<edges.size();i++) {
            edges[i].push_back(i);
        }
        sort(edges.begin(),edges.end(),[](vector<int> &a,vector<int> &b) {
            return a[2]<b[2];
        });

        vector<int> critical,non_critical;

        int original_MST=getMST(edges,n);

        for(int i=0;i<edges.size();i++) {
            if(getMST(edges,n,-1,i) > original_MST) {
                critical.push_back(edges[i][3]);
            }
            else if(getMST(edges,n,i) == original_MST) {
                non_critical.push_back(edges[i][3]);
            }
        }

        return {critical,non_critical};

    }
};
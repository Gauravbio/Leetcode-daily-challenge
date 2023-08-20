class Solution {
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {

        for(int i=0;i<n;i++) {
            if(group[i]==-1) {
                group[i]=m;
                m++;
            }
        }

        vector<int> groupAdj[m];
        vector<int> itemAdj[n];
        map<int,vector<int>> itgrmp;
        vector<int> groupIn(m,0);
        vector<int> itemIn(n,0);

        for(int i=0;i<n;i++) {
            itgrmp[group[i]].push_back(i);
            for(auto item: beforeItems[i]) {
                if(group[i]!=group[item]) {
                    groupIn[group[i]]++;
                    groupAdj[group[item]].push_back(group[i]);
                }
                else {
                    itemIn[i]++;
                    itemAdj[item].push_back(i);
                }
            }
        }

        queue<int> gr;
        vector<int> groupAns;
        for(int i=0;i<m;i++) {
            if(groupIn[i]==0) {
                gr.push(i);
            }
        }

        while(!gr.empty()) {
            int front=gr.front();
            groupAns.push_back(front);
            gr.pop();

            for(auto it: groupAdj[front]) {
                groupIn[it]--;
                if(groupIn[it]==0) {
                    gr.push(it);
                }
            }
        }

        vector<int> ans;

        if(groupAns.size()!=m) return ans;

        for(int i=0;i<m;i++) {
            int curr_gr=groupAns[i];
            queue<int> q;
            for(auto node: itgrmp[curr_gr]) {
                if(itemIn[node]==0) q.push(node);
            }

            while(!q.empty()) {
                int front=q.front();
                ans.push_back(front);
                q.pop();

                for(auto node: itemAdj[front]) {
                    itemIn[node]--;
                    if(itemIn[node]==0) {
                        q.push(node);
                    }
                }
            }
        }

        if(ans.size()!=n) return {};
        return ans;
    }   
};
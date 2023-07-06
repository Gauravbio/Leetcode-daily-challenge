class Solution {
    private:
    bool isValid(int r,int c,int m,int n,map<pair<int,int>,int> &count,int day) {
        if(r<0 || c<0 || r>=m || c>=n) return 0;
        else if(count.find({r,c})!=count.end()) {
            if(day>=count[{r,c}]) return 0;
        }
        return 1;
    }

    //bfs
    bool isPath(int day,int row, int col,map<pair<int,int>,int> &count) { 
        queue<pair<int,int>> q;
        vector<vector<bool>> vis(row,vector<bool> (col,0));

        for(int i=0;i<col;i++) {
            if(isValid(0,i,row,col,count,day)) {
                q.push({0,i});
                vis[0][i]=1;
            }
        }

        int drow[]={0,-1,1,0};
        int dcol[]={1,0,0,-1};

        while(!q.empty()) {
            auto front=q.front();
            int r=front.first;
            int c=front.second;
            q.pop();
            if(r==row-1) return 1;

            for(int i=0;i<4;i++) {
                int nrow=r+drow[i];
                int ncol=c+dcol[i];

                if(isValid(nrow,ncol,row,col,count,day) && !vis[nrow][ncol]) {
                    q.push({nrow,ncol});
                    vis[nrow][ncol]=1;
                }
            }
        }

        return 0;
    }
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        map<pair<int,int>,int> count;
        int n=cells.size();

        for(int i=0;i<n;i++) {
            int r=cells[i][0];
            int c=cells[i][1];
            count[{r-1,c-1}]=i+1;
        }


        int start=1;
        int end=n;
        int ans=0;
        while(start<=end) {
            int mid=start+(end-start)/2;
            if(isPath(mid,row,col,count)) {
                ans=mid;
                start=mid+1;
            }
            else {
                end=mid-1;
            }
        }

        return ans;
        
    }
};
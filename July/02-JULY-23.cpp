class Solution {
    private:
    void solve(int n,vector<vector<int>>& requests,unordered_map<int,int> &count,int index,int fulfilled,int &ans) {
        if(index==n) {
            bool flag=0;
            for(auto it: count) {
                if(it.second!=0) {
                    flag=1;
                    break;
                }
            }

            if(flag) return ;
            ans=max(fulfilled,ans);
            return ;
        }
        // cout<<"yaha";
        solve(n,requests,count,index+1,fulfilled,ans);
        count[requests[index][0]]++;
        count[requests[index][1]]--;
        // cout<<index<<" ";

        solve(n,requests,count,index+1,fulfilled+1,ans);
        count[requests[index][0]]--;
        count[requests[index][1]]++;
    }
public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        unordered_map<int,int> count; 
        int ans=0;
        solve(requests.size(),requests,count,0,0,ans);
        return ans;
    }
};
class Solution {
public:
    map<pair<int,int>,vector<vector<int>>> mp;
    void solve(vector<vector<int>> &ans,int n,int k,vector<int> &output,int num) {
        if(k==0) {
            ans.push_back(output);
            return ;
        }
        if((n+1)==num) return ;

        for(int i=num;i<=n;i++) {
            output.push_back(i);
            solve(ans,n,k-1,output,i+1);
            output.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> output;
        solve(ans,n,k,output,1);
        return ans;
    }
};
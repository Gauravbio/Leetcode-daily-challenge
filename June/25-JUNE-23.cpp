class Solution {
public:
int mod=1e9+7;
    int solve(vector<int>& locations, int start, int finish, int fuel,int n
    ,vector<vector<int>> &dp) {

        if(dp[start][fuel]!=-1) return dp[start][fuel];
        long long ans=0;
        for(int i=0;i<n;i++) {
            int req=abs(locations[start]-locations[i]);
            if(i!=start && fuel>=req) {
                if(finish==i) 
                    ans+=(1+1ll*solve(locations,i,finish,fuel-req,n,dp))%mod;
                else {
                    ans+=(solve(locations,i,finish,fuel-req,n,dp))%mod;
                }
            }
        }

        dp[start][fuel]= ans%mod;
        return dp[start][fuel];
    }

    
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int n=locations.size();
        vector<vector<int>> dp(n,vector<int> (fuel+1,-1));
        int ans=solve(locations,start,finish,fuel,n,dp);
        if(start==finish) ans++;
        return ans%mod;
    }
};
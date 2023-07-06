class Solution {

    long long calcCost(vector<int>& nums, vector<int>& cost,int target) {
        long long ans=0;
        int n=cost.size();

        for(int i=0;i<n;i++) {
            int dist=abs(target-nums[i]);
            ans+=(1ll*dist*cost[i]);
        }
        return ans;
    }
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int low=1;
        int high=1e6;
        long long ans=1e17;

        while(low<high) {
            int mid= (low+high)/2;

            long long currPoint = calcCost(nums,cost,mid);
            long long nextPoint = calcCost(nums,cost,mid+1);
            // cout<<currPoint<<" "<<nextPoint<<endl;
            ans=min(ans,min(currPoint,nextPoint));

            if(currPoint>nextPoint) {
                low=mid+1;
            }
            else high=mid-1;
        }

        return ans;
    }
};
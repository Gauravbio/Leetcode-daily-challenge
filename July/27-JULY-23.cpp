class Solution {
    bool check(vector<int>& batteries,int n,int m,long long time) {
        long long act_time=0;
        for(int i=0;i<m;i++) {
            if(batteries[i]<time) act_time+=batteries[i];
            else act_time+=time;
        }

        return (act_time/n)>=time;
    }
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long start=0;
        long long end=0;
        long long ans=0;
        int m=batteries.size();

        for(int i=0;i<m;i++) end+=batteries[i];

        while(start<=end) {
            long long mid=start+(end-start)/2;
            if(check(batteries,n,m,mid)) {
                ans=mid;
                start=mid+1;
            }
            else end=mid-1;
        }

        return ans;
    }
};
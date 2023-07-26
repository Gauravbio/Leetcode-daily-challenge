class Solution {
    private:
    bool check(double speed,vector<int>& dist, double hour,int n) {
        double time=0;

        for(int i=0;i<n-1;i++) {
            time+=ceil(dist[i]/speed);
        }
        
        time+=(dist[n-1]/speed);
        return hour>=time;
    }
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n=dist.size();
        if(int(hour)<(n-1)) return -1;

        int start=1;
        int end=1e7+1;
        int speed=-1;

        while(start<=end) {
            int mid=start+(end-start)/2;

            if(check(mid,dist,hour,n)) {
                speed=mid;
                end=mid-1;
            }
            else start=mid+1;
        }

        return speed;
    }
};
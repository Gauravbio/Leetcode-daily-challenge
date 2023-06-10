class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        int start=1,end=maxSum;
        int ans=0;
        int right=n-index-1;
        int left=index;

        while(start<=end) {
            int mid=start+(end-start)/2;
            long long capacity=mid-1;
            long long rightSum=0,leftSum=0;

            if(right<=capacity) {
                long long item=capacity-right;
                rightSum=(capacity*(capacity+1)/2)-(item*(item+1)/2);
            }
            else {
                rightSum=(capacity*(capacity+1)/2)+(right-capacity);
            }

            if(left<=capacity) {
                long long item=capacity-left;
                leftSum=(capacity*(capacity+1)/2)-(item*(item+1)/2);
            }
            else {
                leftSum=(capacity*(capacity+1)/2)+(left-capacity);
            }

            long long sum=leftSum+mid+rightSum;

            if(sum<=maxSum) {
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
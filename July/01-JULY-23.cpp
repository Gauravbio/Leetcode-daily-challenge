class Solution {
    private:
    int distribution(vector<int>& cookies, int k,vector<int> &children,int &ans,int index,int n)  {
        if(index==n) {
            int maxi=INT_MIN;
            for(int i=0;i<k;i++) {
                maxi=max(children[i],maxi);
            }
            ans=min(ans,maxi);
            return ans;
        }

        int currMin=1e9;
        for(int i=0;i<k;i++) {
            children[i]+=cookies[index];
            currMin=min(currMin,distribution(cookies,k,children,ans,index+1,n));
            children[i]-=cookies[index];
        }

        return currMin;
    }
public:
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> children(k,0);

        int ans=1e9;
        int n=cookies.size();
        distribution(cookies,k,children,ans,0,n);
        return ans;
    }
};
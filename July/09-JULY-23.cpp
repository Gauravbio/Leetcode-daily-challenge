class Solution {
public:
    int largestVariance(string s) {
        int n=s.size();
        if(n==1) return 0;
        int count[26]={0};
        int ans=0;

        for(int i=0;i<n;i++) {
            count[s[i]-'a']++;
        }

        for(int i=0;i<26;i++) {
            for(int j=0;j<26;j++) {
                if(count[i]==0 || count[j]==0 || i==j) continue;

                char ch1='a'+i;
                char ch2='a'+j;
                int major=0,minor=0;
                
                int rest=count[j];

                for(char c: s) {
                    if(c==ch1) major++;
                    if(c==ch2) {
                        minor++;
                        rest--;
                    }

                    if(minor>0) ans=max(ans,major-minor);

                    if(major<minor && rest>0) {
                        major=0;
                        minor=0;
                    }
                }

            }
        }
        return ans;
    }
};
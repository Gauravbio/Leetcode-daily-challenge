class Solution {
public:
// approach-1
    bool repeatedSubstringPattern(string s) {
        int n=s.size();
        bool ans=0;
        for(int i=0;i<n/2+1;i++) {
            string sub=s.substr(0,i+1);
            int temp=0;
            for(int j=i+1;j<n;) {
                while(j<n && temp<sub.size() && sub[temp]==s[j]) {
                    j++,temp++;
                }
                if(temp==sub.size() && j==n) {
                    return 1;
                }
                if(temp!=sub.size()) break;
                temp=0;
            }
        }

        return 0;
    }

    // approach-2
    bool repeatedSubstringPattern(string s) {
        string temp=s;
        temp+=s;

        if(temp.substr(1,temp.size()-2).find(s)!=-1) return true;
        return false;
    }
};
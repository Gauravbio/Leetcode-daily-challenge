class Solution {
public:
    bool buddyStrings(string s, string goal) {
        int n=s.size();
        int g=goal.size();
        if(n!=g) return 0;

        int count[26]={0};
        vector<int> v;

        for(int i=0;i<n;i++) {
            count[s[i]-'a']++;
            if(s[i]!=goal[i]) {
                v.push_back(i);
                if(v.size()>2) return 0;
            }
        }

        if(v.size()==2) {
            if(s[v[0]]==goal[v[1]] && s[v[1]]==goal[v[0]]) return 1;
        }
        else if(v.size()==0) {
            int duplicates=0;

            for(int i=0;i<26;i++) {
                if(count[i]>=2) return 1;
            }
        }

        return 0;
    }
};
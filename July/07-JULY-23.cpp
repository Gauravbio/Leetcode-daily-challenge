class Solution {
    int n;
    int checkTrue(string answerKey, int k) {
        int i=0;
        int ans=0;
        for(int j=0;j<n;j++) {
            if(answerKey[j]=='F') k--;
            while(i<=j && k<0) {
                if(answerKey[i]=='F') k++;
                i++;
            }
            ans=max(j-i+1,ans);
        }

        return ans;
    }
    int checkFalse(string answerKey, int k) {
        int i=0;
        int ans=0;
        for(int j=0;j<n;j++) {
            if(answerKey[j]=='T') k--;
            while(i<=j && k<0) {
                if(answerKey[i]=='T') k++;
                i++;
            }
            ans=max(j-i+1,ans);
        }

        return ans;
    }
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        n=answerKey.size();
        return max(checkTrue(answerKey,k),checkFalse(answerKey,k));
    }
};